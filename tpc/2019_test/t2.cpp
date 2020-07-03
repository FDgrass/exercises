#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    scanf("%d %d", &n, &m);
    std::vector<int> num(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &num[i]);
    }
    std::sort(num.begin(), num.end());
    long long ans = 0;
    for (int i = 0, j = m * 2 - 1; i < m; ++i, --j) {
      ans += num[i] * num[j];
    }
    printf("%lld\n", ans);
  }

  return 0;
}