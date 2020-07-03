#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
  int n;
  string name;
  cin >> n >> name;
  vector<int> candi;
  int cc[301];
  for(int i = 0; i < 301; ++i) cc[i] = 0;
  for(int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    cc[tmp]++;
  }
  for(int i = 1; i < 301; ++i) {
    if(cc[i] != 0) {
      candi.push_back(cc[i]);
    }
  }
  sort(candi.begin(), candi.end());
  string ans;
  if(name == "Alice") {
    if(candi[0] <= 2) {
      ans = "Alice";
    } else {
      ans = "Bob";
    }
  } else if(name == "Bob") {
    if(candi[0] == 1 || candi[1] <= 2) {
      ans = "Alice";
    } else {
      ans = "Bob";
    }
  }
  printf("%s\n", ans.c_str());

  return 0;
}