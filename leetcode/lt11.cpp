#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

class Solution {
 public:
  int maxArea(std::vector<int>& height) {
    int ans = 0;
    for (int i = 0, j = height.size() - 1; j > i;) {
      int l = j - i;
      int h = std::min(height[i], height[j]);
      ans = std::max(ans, l * h);
      if (height[i] > height[j])
        --j;
      else
        ++i;
    }
    return ans;
  }
};
int main() {
  Solution s;
  {
    std::vector<int> vec{1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << s.maxArea(vec) << std::endl;
  }
  return 0;
}