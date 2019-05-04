#include <iostream>
#include <sstream>
#include <atomic>
#include <memory>
#include <cassert>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

class Solution {
public:
  explicit Solution(size_t case_number):
      case_number_(case_number) {
    read_input();
  }

  void print_answer();
  void solve();

private:
  void read_input();

  size_t case_number_;
};

void Solution::read_input() {

}

void Solution::solve() {

}

void Solution::print_answer() {
  cout << "Case #" << case_number_ + 1 << ": " << endl;
}

int main() {
  size_t case_count;
  cin >> case_count;
  vector<Solution> solutions;
  for (size_t i = 0; i < case_count; ++i) {
    solutions.emplace_back(i);
  }

  for (auto& solution : solutions) {
    solution.solve();
  }

  for (auto& solution : solutions) {
    solution.print_answer();
  }
}

