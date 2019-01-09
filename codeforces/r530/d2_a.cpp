#include <iostream>

using namespace std;

int main() {
  int w, h;
  cin >> w >> h;
  int h1, w1;
  int h2, w2;
  cin >> w1 >> h1;
  cin >> w2 >> h2;

  int ans = w;
  for (int i = h; i >= 0; --i) {
    ans += i;
    if (i == h1) {
      ans -= w1;
      ans = max(ans, 0);
    }
    if (i == h2) {
      ans -= w2;
      ans = max(ans, 0);
    }
    // cout << i << " " << ans << endl;
  }

  cout << ans << endl;

  return 0;
}