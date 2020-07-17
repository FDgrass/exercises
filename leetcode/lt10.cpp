#include <iostream>
#include <map>
#include <unordered_map>

class Solution {
 public:
  bool isMatch(std::string s, std::string p) {
    p_.clear();
    for (auto& c : p) {
      if (c == '*' && p_.back() == '*') {
        continue;
      }
      p_.push_back(c);
    }
    s_ = s;
    // dp_status_.clear();

    return isMatchImpl(s_.size() - 1, p_.size() - 1);
  }

 private:
  bool isMatchImpl(int i, int j) {
    // printf("i %d j %d\n", i, j);
    if (i < 0 && j < 0)
      return true;
    else if (j < 0)
      return false;
    ;
    // if (dp_status_.count(std::make_pair(i, j)) != 0) return dp_status_[std::make_pair(i, j)];

    bool ans = false;
    if (p_[j] == '*') {
      if (isMatchImpl(i, j - 2)) {
        ans = true;
      } else if (i < 0) {
        ans = false;
      } else {
        ans =
            ((p_[j - 1] == s_[i] || p_[j - 1] == '.') && isMatchImpl(i - 1, j));
      }
    } else if (i >= 0 && (p_[j] == '.' || p_[j] == s_[i])) {
      ans = isMatchImpl(i - 1, j - 1);
    }
    // dp_status_[std::make_pair(i, j)] = ans;
    // std::cout << i << " " << j << " " << ans << std::endl;
    return ans;
  }

  std::string s_, p_;
  // std::map<std::pair<int, int>, bool> dp_status_;
};

int main() {
  Solution s;
  // std::cout << s.isMatch("aa", "a") << std::endl;
  // std::cout << s.isMatch("aa", "a*") << std::endl;
  // std::cout << s.isMatch("ab", ".*") << std::endl;
  // std::cout << s.isMatch("aab", "c*a*b") << std::endl;
  // std::cout << s.isMatch("mississippi", "mis*is*p*.") << std::endl;
  // std::cout << s.isMatch("ab", ".*") << std::endl;
  std::cout << s.isMatch("aaa", "aaaa") << std::endl;
  return 0;
}