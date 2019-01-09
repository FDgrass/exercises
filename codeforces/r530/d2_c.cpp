#include <iostream>

using namespace std;

int main() {
  int k;
  string str;
  cin >> str >> k;
  int t = 0;
  bool has_xh = 0;

  for (auto &c : str) {
    if (c == '*' || c == '?') {
      ++t;
      if (c == '*') {
        has_xh = 1;
      }
    }
  }

  string ans;
  if (str.size() - t * 2 > k || t == 0 && str.size() != k ||
      str.size() - t < k && !has_xh) {
    cout << "Impossible" << endl;
  } else {
    int size = str.size() - t;
    for (auto &c : str) {
      if (c != '*' && c != '?') {
        ans.push_back(c);
      } else {
        if (size == k) {
          continue;
        } else if (size < k && !ans.empty()) {
          if (c == '*') {
            while (size < k) {
              ans.push_back(ans.back());
              ++size;
            }
          } else {
            continue;
          }
        } else if (size > k && !ans.empty()) {
          ans.pop_back();
          --size;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}