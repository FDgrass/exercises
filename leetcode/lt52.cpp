#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  int totalNQueens(int n) {
    int result = 0;
    std::vector<bool> used(5 * n - 2, false);
    std::vector<std::pair<int, int>> queens;
    queens.reserve(n);

    solveNQueensDfsImpl(result, used, queens, 0, n);
    return result;
  }

 private:
  void solveNQueensDfsImpl(int& result, std::vector<bool>& used,
                           std::vector<std::pair<int, int>>& queens, int depth,
                           int n) {
    if (depth == n) {
      result++;
      // std::cout << n << std::endl;
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (!used[i] && !used[i - depth + 17] && !used[i + depth + 26]) {
        used[i] = true;
        used[i - depth + 17] = true;
        used[i + depth + 26] = true;
        queens.emplace_back(depth, i);

        solveNQueensDfsImpl(result, used, queens, depth + 1, n);

        queens.pop_back();
        used[i] = false;
        used[i - depth + 17] = false;
        used[i + depth + 26] = false;
      }
    }
  }
};

int main() {
  Solution s;

  {
    for (int i = 1; i < 10; ++i) {
      std::cout << s.totalNQueens(i) << std::endl;
    }
  }
}