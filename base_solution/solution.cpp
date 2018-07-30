#include <iostream>
#include <sstream>
#include <atomic>
#include <memory>
#include <cassert>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

constexpr size_t kMaxThreadsCount = 15;

namespace logger {
  mutex logs_mutex;
};

#define log(log_message, method_name, class_name)\
{\
  lock_guard<mutex> lock(logger::logs_mutex);\
  clog << '[' << class_name << "::" << method_name << "]: " << log_message << endl;\
}


class Solution {
protected:
  explicit Solution(size_t case_number):
      case_number_(case_number) {
    read_input();
  }

  void read_input() {}
  void solve_internal() {}
  void print_result() {}

  size_t case_number_;
};

class AsyncSolution : Solution {
public:
  AsyncSolution(size_t case_number, atomic<size_t>& free_threads_count):
      Solution(case_number),
      free_threads_count_(free_threads_count) {}

  void start_solving_thread() {
    assert(free_threads_count_ > 0);
    --free_threads_count_;
    solving_thread_ = make_unique<thread>([this]{this->solve();});
  }

  void join() {
    solving_thread_->join();
  }

private:
  void solve() {
    log("start solution " << case_number_, "solve", "AsyncSolution");
    solve_internal();
    log("finish solution " << case_number_, "solve", "AsyncSolution");
    ++free_threads_count_;
  }

  atomic<size_t>& free_threads_count_;
  unique_ptr<thread> solving_thread_;
};

int main() {
  atomic<size_t> free_threads_count = kMaxThreadsCount;

  size_t case_count;
  cin >> case_count;
  vector<AsyncSolution> solutions;
  for (size_t i = 0; i < case_count; ++i) {
    solutions.emplace_back(i, free_threads_count);
  }
  log("solutions initialized", "main", "");

  for (auto& solution : solutions) {
    solution.start_solving_thread();
    while (free_threads_count == 0) {}
  }
  for (auto& solution : solutions) {
    solution.join();
  }
  log("all solutions finished", "main", "");
}
