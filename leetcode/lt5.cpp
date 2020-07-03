#include <iostream>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int cur_len = 0;
    std::string ret;
    std::pair<int, int> ans;
    for (int i = 0; i < s.size(); ++i) {
      int len = -1;
      int l = i, r = i;
      for (; l >= 0 && r < s.size(); --l, ++r, len += 2) {
        if (s[l] != s[r]) {
          break;
        }
      }
      // printf("cur_len %d\n", cur_len);
      if (len > cur_len) {
        cur_len = len;
        ans = std::make_pair(l + 1, r - l - 1);
      }

      len = 0;
      l = i, r = i + 1;
      for (; l >= 0 && r < s.size(); --l, ++r, len += 2) {
        if (s[l] != s[r]) {
          break;
        }
      }
      // printf("cur_len %d\n", cur_len);
      if (len > cur_len) {
        cur_len = len;
        ans = std::make_pair(l + 1, r - l - 1);
      }
    }
    ret = std::string(s, ans.first, ans.second);
    return ret;
  }
};

int main() {
  Solution s;
  {
    std::string str = "babad";
    printf("%s\n", s.longestPalindrome(str).c_str());
  }
  {
    std::string str = "cbbd";
    // printf("t: %s\n", std::string(str, 1, 3).c_str());
    printf("%s\n", s.longestPalindrome(str).c_str());
  }
  {
    std::string str = "bb";
    printf("%s\n", s.longestPalindrome(str).c_str());
  }
  return 0;
}