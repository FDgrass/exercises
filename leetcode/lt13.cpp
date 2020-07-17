#include <iostream>

class Solution {
 public:
  int romanToInt(std::string s) {
    int ans = 0;
    char pre = 0;
    for (auto it = s.begin(); it != s.end(); ++it) {
      if (*it == 'M') {
        ans += 1000;
        if (pre == 'C') {
          ans -= 200;
        }
      } else if (*it == 'D') {
        ans += 500;
        if (pre == 'C') {
          ans -= 200;
        }
      } else if (*it == 'C') {
        ans += 100;
        if (pre == 'X') {
          ans -= 20;
        }
      } else if (*it == 'L') {
        ans += 50;
        if (pre == 'X') {
          ans -= 20;
        }
      } else if (*it == 'X') {
        ans += 10;
        if (pre == 'I') {
          ans -= 2;
        }
      } else if (*it == 'V') {
        ans += 5;
        if (pre == 'I') {
          ans -= 2;
        }
      } else if (*it == 'I') {
        ans += 1;
      }
      pre = *it;
    }
    return ans;
  }
};

int main() {
  Solution s;
  std::cout << s.romanToInt("III") << std::endl;
  std::cout << s.romanToInt("IV") << std::endl;
  std::cout << s.romanToInt("IX") << std::endl;
  std::cout << s.romanToInt("LVIII") << std::endl;
  std::cout << s.romanToInt("MCMXCIV") << std::endl;

  return 0;
}