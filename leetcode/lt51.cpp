#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> result;
    std::vector<bool> used(5 * n - 2, false);
    std::vector<std::pair<int, int>> queens;
    queens.reserve(n);

    solveNQueensDfsImpl(result, used, queens, 0, n);
    return result;
  }

 private:
  void solveNQueensDfsImpl(std::vector<std::vector<std::string>>& result,
                           std::vector<bool>& used,
                           std::vector<std::pair<int, int>>& queens, int depth,
                           int n) {
    if (depth == n) {
      std::vector<std::string> board(n, std::string(n, '.'));
      for (auto& pos : queens) {
        board[pos.first][pos.second] = 'Q';
      }
      result.push_back(board);
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
    auto result = s.solveNQueens(4);
    for (auto& board : result) {
      for (auto& row : board) {
        std::cout << row << std::endl;
      }
      std::cout << std::endl;
    }
  }

  {
    for (int i = 1; i < 10; ++i) {
      std::cout << s.solveNQueens(i).size() << std::endl;
    }
  }
}