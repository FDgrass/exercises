#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int inf = 1e9 + 7;
const int max_num = 3e5 + 10;


int main(){
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> l_num(n), r_num(n);
    for(int i = 0; i < n; ++i) {
      cin >> l_num[i] >> r_num[i];
    }
    vector<int> stat(n + 1);
    for(int i = 0; i < n + 1; ++i) stat[i] = inf;

    for(int i = 0; i < n; ++i) {
      int pos = lower_bound(stat.begin(), stat.end(), r_num[i]) - stat.begin();
      while(pos >= 0 && stat[pos] > l_num[i]) {
        if(pos == 0) {
          stat[pos] = min(l_num[i], stat[pos]);
        } else {
          stat[pos] = min(max(l_num[i], stat[pos - 1] + 1), stat[pos]);
        }
        --pos;
      }
    }
    int ans = lower_bound(stat.begin(), stat.end(), inf) - stat.begin();
    printf("%d\n", ans);
  }
  return 0;
}