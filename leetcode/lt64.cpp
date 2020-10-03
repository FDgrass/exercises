#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minPathSum(std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> dp_stat(grid.size(),
                                          std::vector<int>(grid[0].size()));

    dp_stat[0][0] = grid[0][0];
    for (int i = 1; i < grid.size(); ++i) {
      dp_stat[i][0] = dp_stat[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < grid[0].size(); ++j) {
      dp_stat[0][j] = dp_stat[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < grid.size(); ++i) {
      for (int j = 1; j < grid[i].size(); ++j) {
        dp_stat[i][j] = std::min(dp_stat[i][j - 1] + grid[i][j],
                                 dp_stat[i - 1][j] + grid[i][j]);
      }
    }
    return dp_stat[grid.size() - 1][grid[0].size() - 1];
  }
};

int main() {
  Solution s;
  {
    std::vector<std::vector<int>> grid{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };
    auto result = s.minPathSum(grid);
    std::cout << result << std::endl;
  }

  return 0;
}