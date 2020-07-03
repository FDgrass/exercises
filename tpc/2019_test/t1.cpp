#include <stdio.h>

#include <iostream>
#include <vector>

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> num(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> num[i];
    }
    int ans;
    while (true) {
      int max_num = -1e9, max_id = -1, min_num = 1e9, min_id = -1;
      for (int i = 0; i < n; ++i) {
        if (num[i] > max_num) {
          max_num = num[i];
          max_id = i;
        }
        if (num[i] < min_num) {
          min_num = num[i];
          min_id = i;
        }
      }
      if (max_num == min_num) {
        ans = max_num;
        break;
      } else {
        num[max_id] = num[min_id] = max_num - min_num;
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}