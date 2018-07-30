using namespace std;

class Solution : AsyncSolution {
public:
  explicit Solution(size_t case_number, atomic<size_t>& free_threads_count):
      AsyncSolution(case_number, free_threads_count),
      case_number_(case_number) {
    read_input();
  }

  void print_result() override {}

protected:
  void solve_internal() override {}

private:
  void read_input() {}

  size_t case_number_;
};

