#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    int max_prefix_size = 0;
    for (auto& str : strs)
      max_prefix_size = std::max(max_prefix_size, (int)str.size());
    std::string prefix;
    for (int i = 0; i < max_prefix_size; ++i) {
      bool add = true;
      char c = strs[0][i];
      // std::cout << i << " " << c << std::endl;
      for (int j = 1; j < strs.size(); ++j) {
        if (c != strs[j][i]) {
          add = false;
          break;
        }
      }
      if (!add) {
        break;
      } else {
        prefix.push_back(c);
      }
    }
    return prefix;
  }
};
int main() {
  Solution s;
  {
    std::vector<std::string> strs{"flower", "flow", "flight"};
    std::cout << s.longestCommonPrefix(strs) << std::endl;
  }
  {
    std::vector<std::string> strs{"dog", "racecar", "car"};
    std::cout << s.longestCommonPrefix(strs) << std::endl;
  }
  return 0;
}