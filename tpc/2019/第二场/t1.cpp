#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--) {
    string src_ip;
    cin >> src_ip;
    vector<string> strs;
    strs.push_back("");
    for(int i = 0; i < src_ip.size(); ++i) {
      char c = src_ip[i];
      if(c == ':') {
        if(strs.back().empty() && i != 1) {
          strs.back().push_back('-');
          strs.push_back("");
        } else {
          strs.push_back("");
        }
      } else {
        strs.back().push_back(c);
      }
    }
    if(strs.back().empty()) strs.pop_back();
    // for(auto &str : strs) {
    //   printf("%s\n", str.c_str());
    // }
    string ans;
    for(auto &str : strs) {
      if(str == "-") {
        int t_n = 8 - strs.size() + 1;
        while(t_n--) {
          if(!ans.empty()) {
            ans.append(":");
          }
          ans.append("0000");
        }
      } else {
        if(!ans.empty()) {
          ans.append(":");
        }
        int t_n = 4 - str.size();
        while(t_n--) {
          ans.append("0");
        }
        ans.append(str);
      }
    }
    printf("%s\n", ans.c_str());
  }

  return 0;
}