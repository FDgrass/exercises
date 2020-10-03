#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;

    std::map<int, int> nums_count;
    for (auto& num : nums) {
      nums_count[num]++;
    }
    std::vector<std::pair<int, int>> nums_stats(nums_count.begin(),
                                                nums_count.end());

    std::vector<int> seq;
    seq.reserve(nums.size());
    std::vector<int> used(nums.size(), 0);
    dfs(result, seq, nums_stats, nums.size());
    return result;
  }

 private:
  void dfs(std::vector<std::vector<int>>& result, std::vector<int>& seq,
           std::vector<std::pair<int, int>> nums_stats, int len) {
    if (seq.size() == len) {
      result.push_back(seq);
      return;
    }
    for (int i = 0; i < nums_stats.size(); ++i) {
      if (nums_stats[i].second > 0) {
        seq.push_back(nums_stats[i].first);
        nums_stats[i].second--;
        dfs(result, seq, nums_stats, len);
        nums_stats[i].second++;
        seq.pop_back();
      }
    }
  }
};

int main() {
  Solution s;
  {
    std::vector<int> nums{1, 1, 2};
    auto result = s.permuteUnique(nums);
    for (auto& row : result) {
      for (auto& num : row) {
        std::cout << num << " ";
      }
      std::cout << std::endl;
    }
  }
}