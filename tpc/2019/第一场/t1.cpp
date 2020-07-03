#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    int ans;
    if (n == 1) {
      ans = 1;
    }else {
      ans = n / 2;
    }
    printf("%d\n", ans);
  }
  return 0;
}
