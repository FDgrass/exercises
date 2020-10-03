#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  double myPow(double x, int n) {
    if (n == 0) return 1;
    long long tmp_n;
    if (n < 0) {
      x = 1 / x;
      tmp_n = -((long long)n);
    } else {
      tmp_n = n;
    }
    // std::cout << "tmp_n: " << tmp_n << std::endl;
    double ans = 1;
    double temp = x;
    while (tmp_n > 0) {
      // std::cout << "tmp_n: " << tmp_n << std::endl;
      // std::cout << "ans: " << ans << std::endl;
      if (tmp_n & 1) {
        ans *= temp;
      }
      tmp_n >>= 1;
      temp *= temp;
    }
    return ans;
  }
};

int main() {
  Solution s;
  {
    double x = 2;
    int n = 10;
    std::cout << s.myPow(x, n) << std::endl;
  }
  {
    double x = 2.1;
    int n = 3;
    std::cout << s.myPow(x, n) << std::endl;
  }
  {
    double x = 2;
    int n = -2;
    std::cout << s.myPow(x, n) << std::endl;
  }
  return 0;
}