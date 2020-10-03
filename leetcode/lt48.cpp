#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int half_n = n / 2;
    std::vector<int> swap_vec(4);
    for (int i = 0; i < half_n; ++i) {
      for (int j = 0; j < half_n; ++j) {
        swap_vec[0] = matrix[i][j];
        swap_vec[1] = matrix[j][n - i - 1];
        swap_vec[2] = matrix[n - i - 1][n - j - 1];
        swap_vec[3] = matrix[n - j - 1][i];
        matrix[i][j] = swap_vec[3];
        matrix[j][n - i - 1] = swap_vec[0];
        matrix[n - i - 1][n - j - 1] = swap_vec[1];
        matrix[n - j - 1][i] = swap_vec[2];
      }
    }

    if (n % 2 == 1) {
      for (int i = 0, j = half_n; i < half_n; ++i) {
        swap_vec[0] = matrix[i][j];
        swap_vec[1] = matrix[j][n - i - 1];
        swap_vec[2] = matrix[n - i - 1][n - j - 1];
        swap_vec[3] = matrix[n - j - 1][i];
        matrix[i][j] = swap_vec[3];
        matrix[j][n - i - 1] = swap_vec[0];
        matrix[n - i - 1][n - j - 1] = swap_vec[1];
        matrix[n - j - 1][i] = swap_vec[2];
      }
    }
  }
};

int main() {
  Solution s;
  {
    std::vector<std::vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    s.rotate(matrix);
    for (auto& row : matrix) {
      for (auto& num : row) {
        std::cout << num << " ";
      }
      std::cout << std::endl;
    }
  }
  {
    std::vector<std::vector<int>> matrix{
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16},
    };
    s.rotate(matrix);
    for (auto& row : matrix) {
      for (auto& num : row) {
        std::cout << num << " ";
      }
      std::cout << std::endl;
    }
  }
  return 0;
}