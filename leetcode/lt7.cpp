#include <iostream>
#include <string>

class Solution {
 public:
  int reverse(int x) {
    int ret = 0;
    bool is_negative = false;
    is_negative = x < 0;
    while (x != 0) {
      if ((!is_negative && ret > INT_MAX / 10) ||
          (is_negative && ret < INT_MIN / 10)) {
        return 0;
      }
      ret *= 10;
      if ((!is_negative && ret > INT_MAX - (x % 10)) ||
          (is_negative && ret < INT_MIN - (x % 10))) {
        return 0;
      }
      ret += x % 10;
      x /= 10;
    }
    return ret;
  }
};
int main() {
  Solution s;
  std::cout << s.reverse(123) << std::endl;
  std::cout << s.reverse(-123) << std::endl;
  std::cout << s.reverse(120) << std::endl;
  std::cout << s.reverse(1534236469) << std::endl;
}