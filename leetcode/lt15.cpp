#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ret;
    if (nums.size() < 3) return ret;

    for (int i = 0; i < nums.size(); ++i) {
      if (i != 0 && nums[i] == nums[i - 1]) continue;
      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        // std::cout << i << " " << j << " " << k << std::endl;
        if (nums[i] + nums[j] + nums[k] > 0) {
          int t_k = k;
          while (t_k >= 0 && nums[t_k] == nums[k]) --t_k;
          k = t_k;
        } else if (nums[i] + nums[j] + nums[k] < 0) {
          int t_j = j;
          while (t_j < nums.size() && nums[t_j] == nums[j]) ++t_j;
          j = t_j;
        } else {
          std::vector<int> vec{nums[i], nums[j], nums[k]};
          ret.push_back(vec);
          int t_k = k;
          while (t_k >= 0 && nums[t_k] == nums[k]) --t_k;
          k = t_k;
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution s;
  {
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> ans = s.threeSum(nums);
    for (auto& vec : ans) {
      for (auto& num : vec) {
        std::cout << num << " ";
      }
      std::cout << std::endl;
    }
  }
  {
    std::vector<int> nums{0, 0, 0, 0, 0};
    std::vector<std::vector<int>> ans = s.threeSum(nums);
    for (auto& vec : ans) {
      for (auto& num : vec) {
        std::cout << num << " ";
      }
      std::cout << std::endl;
    }
  }

  return 0;
}