// 110101110011
// 110111111111

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int max_size = 5e5 + 5;

char str1[max_size], str2[max_size];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    scanf("%d", &n);
    scanf("%s", str1);
    scanf("%s", str2);
    vector<pair<int, int>> ranges;
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        ranges.emplace_back(0, 0);
      } else if (str2[i] == str2[i - 1]) {
        ranges.back().second = i;
      } else {
        ranges.emplace_back(i, i);
      }
    }
    int ans = 0;
    for (int i = 0; i < ranges.size(); ++i) {
      // printf("%d %d\n", ranges[i].first, ranges[i].second);
      bool with_border = false;
      if (i == 0 || i == ranges.size() - 1) {
        with_border = true;
      }
      int l = ranges[i].first, r = ranges[i].second;
      if ((str1[l] != str2[l] && l != 0) ||
          (str1[r] != str2[r] && r != n - 1)) {
        ans = -1;
        break;
      }
      int dif_num = 0;
      for (int j = l + 1; j <= r; ++j) {
        if (str1[j] != str1[j - 1]) {
          dif_num++;
        }
      }
      if (dif_num % 2 == 1 && !with_border) {
        ans = -1;
        break;
      }
      ans += dif_num / 2 + (dif_num % 2);
      if (l == 0 && r == n - 1) {
        ans++;
      }
      // printf("%d %d, ans %d\n", ranges[i].first, ranges[i].second, ans);
    }
    printf("%d\n", ans);
  }

  return 0;
}