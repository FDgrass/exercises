#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;

    std::vector<int> seq;
    seq.reserve(nums.size());
    std::vector<bool> used(nums.size(), false);
    dfs(result, seq, nums, used);
    return result;
  }

 private:
  void dfs(std::vector<std::vector<int>>& result, std::vector<int>& seq,
           std::vector<int>& nums, std::vector<bool>& used) {
    if (seq.size() == nums.size()) {
      result.push_back(seq);
      return;
    }
    for (int i = 0; i < used.size(); ++i) {
      if (!used[i]) {
        seq.push_back(nums[i]);
        used[i] = true;
        dfs(result, seq, nums, used);
        used[i] = false;
        seq.pop_back();
      }
    }
  }
};

int main() {
  Solution s;
  {
    std::vector<int> nums{1, 2, 3};
    auto result = s.permute(nums);
    for (auto& row : result) {
      for (auto& num : row) {
        std::cout << num << " ";
      }
      std::cout << std::endl;
    }
  }
}