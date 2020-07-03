#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map.clear();
    vector<int> ret;
    for (int i = 0; i < nums.size(); ++i) {
      int t_num = target - nums[i];
      if (map.find(t_num) != map.end()) {
        ret.push_back(i);
        ret.push_back(map[t_num]);
      } else {
        map[nums[i]] = i;
      }
    }
    return ret;
  }

  std::unordered_map<int, int> map;
};

int main() {
  Solution s;
  {
    std::vector<int> nums{2, 7, 11, 5};
    int target = 9;
    std::vector<int> ans = s.twoSum(nums, target);
    printf("%d %d\n", ans[0], ans[1]);
  }

  return 0;
}