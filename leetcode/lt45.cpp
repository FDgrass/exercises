#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  int jump(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    std::vector<int> steps(nums.size(), 1e9 + 7);
    steps[0] = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int step = steps[i] + 1;
      for (int j = std::min(i + nums[i], (int)nums.size() - 1); steps[j] > step;
           --j) {
        steps[j] = step;
      }
      // std::cout << steps[i] << std::endl;
    }
    return steps.back();
  }
};

int main() {
  Solution s;
  {
    std::vector<int> nums{2, 3, 1, 1, 4};
    std::cout << s.jump(nums) << std::endl;
    ;
  }

  return 0;
}