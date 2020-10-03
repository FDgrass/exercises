#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(
      std::vector<std::string>& strs) {
    std::map<std::string, std::vector<std::string>> str_groups;
    for (auto& str : strs) {
      std::string val = str;
      std::sort(val.begin(), val.end());
      str_groups[val].push_back(str);
    }
    std::vector<std::vector<std::string>> result;
    for (auto& pair : str_groups) {
      result.push_back(pair.second);
    }
    return result;
  }
};

int main() {
  Solution s;
  {
    std::vector<std::string> strs{
        "eat", "tea", "tan", "ate", "nat", "bat",
    };
    auto result = s.groupAnagrams(strs);
    for (auto& group : result) {
      for (auto& str : group) {
        std::cout << str << " ";
      }
      std::cout << std::endl;
    }
  }
  return 0;
}