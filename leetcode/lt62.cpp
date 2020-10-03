#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>

struct PairHash {
  size_t operator()(const std::pair<int, int>& x) const {
    return x.first * 100 + x.second;
  }
};

class Solution {
 public:
  // int uniquePaths(int m, int n) {
  //   std::unordered_map<std::pair<int, int>, long long, PairHash> path_nums;
  //   long long result = dfs(m, n, path_nums);
  //   return result;
  // }
  int uniquePaths(int m, int n) {
    std::unordered_map<std::pair<int, int>, long long, PairHash> path_nums;
    long long result = dfs(m, n, path_nums);
    return result;
  }

 private:
  
  long long dfs(
      int m, int n,
      std::unordered_map<std::pair<int, int>, long long, PairHash>& path_nums) {
    if (m == 1 || n == 1) {
      return 1;
    }

    std::pair<int, int> key = std::make_pair(m, n);

    if (path_nums.find(key) != path_nums.end()) {
      return path_nums[key];
    }

    return path_nums[key] = dfs(m - 1, n, path_nums) + dfs(m, n - 1, path_nums);
  }
};

int main() {
  Solution s;
  std::cout << s.uniquePaths(7, 3) << std::endl;
}