#include <iostream>

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    std::string digitals;
    digitals.reserve(15);
    while (x != 0) {
      digitals.push_back(x % 10);
      x /= 10;
    }
    for (int l = 0, r = digitals.size() - 1; l < r; ++l, --r) {
      if (digitals[l] != digitals[r]) return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  std::cout << s.isPalindrome(121) << std::endl;
  std::cout << s.isPalindrome(-121) << std::endl;
  std::cout << s.isPalindrome(10) << std::endl;
  return 0;
}