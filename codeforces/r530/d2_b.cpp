#include <iostream>

using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    if (i * i >= n) {
      ans = i + i;
      break;
    }
    if (i * (i + 1) >= n) {
      ans = i * 2 + 1;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}