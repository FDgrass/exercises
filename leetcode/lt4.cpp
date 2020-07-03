#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    int l1 = 0, r1 = nums1.size(), l2 = 0, r2 = nums2.size();
    while (l1 < r1 || l2 < r2) {
      
    }
  }
};

int main() {
  Solution s;
  {
    std::vector<int> nums1{1, 3};
    std::vector<int> nums2{2};
    printf("%.1lf\n", s.findMedianSortedArrays(nums1, nums2));
  }
  {
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{3, 4};
    printf("%.1lf\n", s.findMedianSortedArrays(nums1, nums2));
  }
  return 0;
}