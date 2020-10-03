#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    long long result = -(1e18 + 7);
    long long tmp = 0;
    for (auto& num : nums) {
      tmp += num;
      result = std::max(result, tmp);
      if (tmp < 0) tmp = 0;
    }
    return (int)result;
  }
};

int main() {
  Solution s;
  {
    std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << s.maxSubArray(nums) << std::endl;
  }

  return 0;
}