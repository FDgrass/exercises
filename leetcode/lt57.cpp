#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,
                                       std::vector<int>& newInterval) {
    std::vector<std::vector<int>> result;
    bool inserted = false;
    for (auto& interval : intervals) {
      if (interval[0] < newInterval[0]) {
        result.push_back(interval);
        if (result.back()[1] >= newInterval[0]) {
          inserted = true;
          result.back()[1] = std::max(result.back()[1], newInterval[1]);
        }
      } else {
        if (!inserted) {
          result.push_back(newInterval);
          inserted = true;
        }
        if (result.back()[1] >= interval[0]) {
          result.back()[1] = std::max(result.back()[1], interval[1]);
        } else {
          result.push_back(interval);
        }
      }
    }

    if (result.empty() || newInterval[0] > result.back()[0]) {
      if (result.empty() || result.back()[1] < newInterval[0]) {
        result.push_back(newInterval);
      } else {
        result.back()[1] = std::max(result.back()[1], newInterval[1]);
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  {
    std::vector<std::vector<int>> intervals{
        {1, 3},
        {6, 9},
    };
    std::vector<int> newInterval{2, 5};
    auto result = s.insert(intervals, newInterval);
    for (auto& interval : result) {
      std::cout << interval[0] << " " << interval[1] << std::endl;
    }
    std::cout << std::endl;
  }
  {
    std::vector<std::vector<int>> intervals{
        {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16},
    };
    std::vector<int> newInterval{4, 8};
    auto result = s.insert(intervals, newInterval);
    for (auto& interval : result) {
      std::cout << interval[0] << " " << interval[1] << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}