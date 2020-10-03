#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  bool isMatch(std::string s, std::string p) {
    std::string clear_p;
    for (auto& c : p) {
      if (c != '*') {
        clear_p.push_back(c);
      } else if (clear_p.empty() || clear_p.back() != '*') {
        clear_p.push_back(c);
      }
    }
    // return isMatchImpl(s, 0, clear_p, 0);
    return isMatchByDP(s, clear_p);
  }

 private:
  bool isMatchByDP(std::string s, std::string p) {
    if (p.empty() && s.empty()) {
      return true;
    } else if (p.empty()) {
      return false;
    } else if (s.empty()) {
      return p == "*";
    }

    std::vector<std::vector<bool>> stat(s.size(),
                                        std::vector<bool>(p.size(), false));

    if (s[0] == p[0] || p[0] == '?') stat[0][0] = true;
    if (p[0] == '*') {
      for (int i = 0; i < s.size(); ++i) {
        stat[i][0] = true;
      }
    }

    if (p.size() > 1) {
      if (p[0] == '*') {
        if (p[1] == '?' || p[1] == s[0]) {
          stat[0][1] = true;
        }
      } else if (stat[0][0]) {
        if (p[1] == '*') {
          stat[0][1] = true;
        }
      }
    }
    if (p.size() > 2) {
      stat[0][2] = p[2] == '*' && stat[0][1];
    }

    for (int i = 1; i < s.size(); ++i) {
      for (int j = 1; j < p.size(); ++j) {
        if (p[j] == '?' || p[j] == s[i]) stat[i][j] = stat[i - 1][j - 1];
        if (p[j] == '*') stat[i][j] = stat[i][j - 1] || stat[i - 1][j];
      }
    }

    // for (int i = 0; i < s.size(); ++i) {
    //   for (int j = 0; j < p.size(); ++j) {
    //     std::cout << stat[i][j] << " ";
    //   }
    //   std::cout << std::endl;
    // }
    return stat[s.size() - 1][p.size() - 1];
  }

  bool isMatchImpl(std::string& s, int index_s, std::string& p, int index_p) {
    if (index_s > s.size()) return false;
    if (s.size() == index_s) {
      if (index_p == p.size()) {
        return true;
      }
      if (p[index_p] == '*') {
        return isMatchImpl(s, index_s, p, index_p + 1);
      } else {
        return false;
      }
    }
    if (index_p == p.size()) {
      return false;
    }

    if (p[index_p] == '?' || (p[index_p] == s[index_s])) {
      return isMatchImpl(s, index_s + 1, p, index_p + 1);
    } else if (p[index_p] == '*') {
      for (int len = 0; len <= s.size() - index_s; ++len) {
        if (isMatchImpl(s, index_s + len, p, index_p + 1)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  {
    std::string str1("aa"), str2("a");
    std::cout << s.isMatch(str1, str2) << std::endl;
  }
  {
    std::string str1("aa"), str2("*");
    std::cout << s.isMatch(str1, str2) << std::endl;
  }
  {
    std::string str1("cb"), str2("?a");
    std::cout << s.isMatch(str1, str2) << std::endl;
  }
  {
    std::string str1("adceb"), str2("*a*b");
    std::cout << s.isMatch(str1, str2) << std::endl;
  }
  {
    std::string str1("acdcb"), str2("a*c?b");
    std::cout << s.isMatch(str1, str2) << std::endl;
  }
  {
    std::string str1("aa"), str2("a*");
    std::cout << s.isMatch(str1, str2) << std::endl;
  }
  {
    std::string str1("ho"), str2("**ho");
    std::cout << s.isMatch(str1, str2) << std::endl;
  }
  return 0;
}