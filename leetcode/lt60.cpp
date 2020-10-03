#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  std::string getPermutation(int n, int k) {
    std::string result;
    std::vector<char> nums;
    nums.reserve(n);
    int t = 1, size = n - 1;
    for (int i = 1; i <= n; ++i) {
      nums.push_back(i + '0');
      t *= i;
    }
    t /= n;

    k -= 1;
    while (size > 0) {
      int i = k / t;
      k = k % t;
      // std::cout << "k : " << k << std::endl;
      // std::cout << "i : " << i << std::endl;
      result.push_back(nums[i]);
      nums.erase(nums.begin() + i);
      t /= size;
      size--;
    }
    result.push_back(nums[0]);
    return result;
  }
};

int main() {
  Solution s;
  std::cout << s.getPermutation(3, 3) << std::endl;
  std::cout << s.getPermutation(4, 9) << std::endl;

  return 0;
}