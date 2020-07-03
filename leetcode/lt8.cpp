#include <iostream>
#include <string>
class Solution {
 public:
  bool PreProcess(const std::string& str, std::string& valid_str) {
    valid_str.clear();
    valid_str.reserve(valid_str.size());
    bool is_first = true;
    for (int i = 0; i < str.size(); ++i) {
      if (is_first) {
        if (str[i] == ' ') {
          continue;
        } else if (str[i] == '-' || str[i] == '+' ||
                   (str[i] >= '0' && str[i] <= '9')) {
          is_first = false;
          valid_str.push_back(str[i]);
          continue;
        } else {
          return false;
        }
      }
      if (str[i] >= '0' && str[i] <= '9') {
        valid_str.push_back(str[i]);
      } else {
        break;
      }
    }
    return true;
  }

  inline bool CheckOverflow1(bool is_negative, int& num) {
    return (!is_negative && num > INT_MAX / 10) ||
           (is_negative && num < INT_MIN / 10);
  }
  inline bool CheckOverflow2(bool is_negative, int& num, int delta) {
    return (!is_negative && num > INT_MAX - delta) ||
           (is_negative && num < INT_MIN + delta);
  }

  int myAtoi(std::string str) {
    std::string valid_str;
    if (!PreProcess(str, valid_str)) {
      return 0;
    }
    if (valid_str.empty()) {
      return 0;
    }
    bool is_negative = valid_str[0] == '-';
    int i = (valid_str[0] == '-' || valid_str[0] == '+') ? 1 : 0;
    int ret = 0;
    for (; i < valid_str.size(); ++i) {
      if (CheckOverflow1(is_negative, ret))
        return !is_negative ? INT_MAX : INT_MIN;
      ret *= 10;
      int digital = valid_str[i] - '0';
      if (CheckOverflow2(is_negative, ret, digital))
        return !is_negative ? INT_MAX : INT_MIN;
      ret += (!is_negative ? digital : -digital);
    }
    return ret;
  }
};
int main() {
  Solution s;
  {
    std::string str("42");
    std::cout << s.myAtoi(str) << std::endl;
  }
  {
    std::string str("   -42");
    std::cout << s.myAtoi(str) << std::endl;
  }
  {
    std::string str("4193 with words");
    std::cout << s.myAtoi(str) << std::endl;
  }
  {
    std::string str("words and 987");
    std::cout << s.myAtoi(str) << std::endl;
  }
  {
    std::string str("-91283472332");
    std::cout << s.myAtoi(str) << std::endl;
  }
  {
    std::string str("3.14159");
    std::cout << s.myAtoi(str) << std::endl;
  }
  return 0;
}