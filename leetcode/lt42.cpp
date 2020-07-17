#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

class Solution {
 public:
  struct Item {
    Item(int t_top, int t_x) : top(t_top), x(t_x) {}
    int top;
    // int bottom;
    int x;
  };

  int trap(std::vector<int>& height) {
    int ans = 0;
    std::stack<Item> st;
    int bottom = 0;
    for (int i = 0; i < height.size(); ++i) {
      Item cur_item(height[i], i);
      // std::cout << i << " " << st.size() << std::endl;
      while (!st.empty()) {
        Item item = st.top();
        int top = std::min(item.top, cur_item.top);
        int h = top - bottom;
        int l = cur_item.x - item.x - 1;
        ans += h * l;
        // std::cout << "ans " << ans << " x " << item.x << std::endl;

        if (cur_item.top <= item.top) {
          st.push(cur_item);
          break;
        }

        st.pop();
        if (!st.empty()) {
          bottom = top;
        }
      }
      if (st.empty()) {
        st.push(cur_item);
        bottom = 0;
      }
    }
    return ans;
  }
};
int main() {
  Solution s;
  {
    std::vector<int> vec{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << s.trap(vec) << std::endl;
  }
  return 0;
}