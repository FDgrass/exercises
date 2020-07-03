#include <iostream>
#include <vector>

class Solution {
 public:
  std::string convert(std::string s, int numRows) {
    if(numRows == 1) {
      return s;
    }
    std::string ret;
    ret.reserve(s.size());
    int cycle = numRows == 1 ? 1 : numRows * 2 - 2;
    for (int i = 0; i < numRows; ++i) {
      int k_offset = cycle - i;
      for (int j = 0; j < s.size(); j += cycle) {
        if (j + i < s.size()) {
          ret.push_back(s[j + i]);
        }

        if (!(i == 0 || i == numRows - 1) && j + k_offset < s.size()) {
          ret.push_back(s[j + k_offset]);
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution s;
  {
    std::string str("PAYPALISHIRING");
    printf("%s\n", s.convert(str, 3).c_str());
  }
  {
    std::string str("PAYPALISHIRING");
    printf("%s\n", s.convert(str, 4).c_str());
  }
  return 0;
}