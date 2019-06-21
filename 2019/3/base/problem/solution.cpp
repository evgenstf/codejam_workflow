#define LOG(message) do { if (enable_logging) { clog << "[" << class_name_ << "::" << __func__ << "]: " << message << endl; } } while (false);

#ifdef DEBUG
#define DBG(message) do { if (enable_logging) { clog << "<" << class_name_ << "::" << __func__ << ">: " << message << endl; } } while (false);
#else
#define DBG(message) do {} while (false);
#endif

#define ASSERT(condition, message) do { if (!(condition)) { LOG(message); exit(1); } } while (false);

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <fstream>
#include <iostream>
#include <memory>
#include <random>
#include <set>
#include <map>
#include <sstream>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>

#define X first
#define Y second
#define PT pair<int, int>
#define mk make_pair
#define ll long long

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

