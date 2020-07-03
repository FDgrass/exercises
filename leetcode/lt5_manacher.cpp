#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  std::string GenManacherString(const std::string& str) {
    std::string ret("#");
    ret.reserve(str.size() * 2 + 1);
    for (const char& c : str) {
      ret.push_back(c);
      ret.push_back('#');
    }
    // std::cout << ret << std::endl;
    return ret;
  }
  string longestPalindrome(string s) {
    std::string manacher_str = GenManacherString(s);
    std::vector<int> p(manacher_str.size(), 0);

    int center = 0, right_point = 0;
    int ans_len = 0, ans_center = 0;
    for (int i = 1; i < manacher_str.size(); ++i) {
      if (i < right_point) {
        int mirror_i = 2 * center - i;
        p[i] = std::min(p[mirror_i], right_point - i);
      }
      int l = i - p[i] - 1, r = i + p[i] + 1;
      // printf("pi %d\n", p[i]);
      while (l >= 0 && r < manacher_str.size()) {
        if (manacher_str[l] != manacher_str[r]) {
          break;
        }
        ++p[i];
        --l, ++r;
      }
      // printf("i %d, c %c, pi %d\n",i, manacher_str[i], p[i]);
      if (i + p[i] > right_point) {
        center = i;
        right_point = i + p[i];
      }

      if (p[i] > ans_len) {
        ans_len = p[i];
        ans_center = i;
      }
    }

    int real_start = (ans_center - p[ans_center]) / 2;
    return std::string(s, real_start, p[ans_center]);
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