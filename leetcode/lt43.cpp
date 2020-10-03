#include <algorithm>
#include <iostream>
class Solution {
 public:
  std::string multiply(std::string num1, std::string num2) {
    std::string result(num1.size() + num2.size(), '0');
    // std::cout << "result: " << result << std::endl;
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    for (int index1 = 0; index1 < num1.size(); ++index1) {
      for (int index2 = 0; index2 < num2.size(); ++index2) {
        int offset = index1 + index2;
        int num = (num1[index1] - '0') * (num2[index2] - '0');
        // std::cout << "num: " << num << std::endl;
        add(result, offset, num);
        // std::cout << "result: " << result << std::endl;
      }
    }
    while (result.size() > 1 && result.back() == '0') {
      result.pop_back();
    }

    std::reverse(result.begin(), result.end());

    return result;
  }

 private:
  inline void add(std::string &result, int offset, int num) {
    while (num > 0) {
      int tmp = result[offset] - '0';
      tmp += num % 10;
      // std::cout << "tmp: " << tmp << std::endl;
      num /= 10;
      num += tmp / 10;
      tmp %= 10;
      // std::cout << "tmp: " << tmp << std::endl;
      result[offset] = tmp + '0';
      offset++;
    }
  }
};
int main() {
  Solution s;
  { std::cout << s.multiply("2", "3") << std::endl; }
  { std::cout << s.multiply("123", "456") << std::endl; }

  return 0;
}