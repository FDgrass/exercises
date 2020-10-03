#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    std::vector<int> result;
    bool add = true;
    for (int p = digits.size() - 1; p >= 0; p--) {
      if (add) {
        int cur_digit = digits[p];
        cur_digit++;
        if (cur_digit > 9) {
          cur_digit = 0;
        } else {
          add = false;
        }
        result.push_back(cur_digit);
      } else {
        result.push_back(digits[p]);
      }
    }
    if (add) {
      result.push_back(1);
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution s;
  {
    std::vector<int> digits{1, 2, 3};
    auto result = s.plusOne(digits);
    for (auto& digit : result) {
      std::cout << digit << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}