#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    int ret = 0;
    bool check[256];
    std::fill(check, check + 256, false);
    for (int i = 0, j = 0; i < s.size(); ++i) {
      int idx = s[i];
      if (check[idx]) {
        while (j < i) {
          int idx_j = s[j];
          check[idx_j] = false;
          if (idx_j == idx) {
            ++j;
            break;
          }
          ++j;
        }
      }

      check[idx] = true;

      // printf("i %d, j %d\n", i, j);
      ret = std::max(ret, i - j + 1);
    }
    return ret;
  }
};

int main() {
  Solution s;
  {
    std::string str("abcabcbb");
    printf("%d\n", s.lengthOfLongestSubstring(str));
  }
  {
    std::string str("bbbbb");
    printf("%d\n", s.lengthOfLongestSubstring(str));
  }
  {
    std::string str("pwwkew");
    printf("%d\n", s.lengthOfLongestSubstring(str));
  }

  return 0;
}