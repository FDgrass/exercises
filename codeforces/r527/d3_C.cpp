#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool used_p[105];

char get_ans(string sub, string str){
    if(sub == str.substr(0, sub.size()) && !used_p[sub.size()]){
        used_p[sub.size()] = 1;
        return 'P';
    }
    return 'S';
}

int main(){
    int n;
    cin >> n;
    
    string str;
    vector <string> sub(2 * n - 2);
    vector <string> max_sub;
    memset(used_p, 0, sizeof(used_p));

    for(auto &ss : sub){
        cin >> ss;
        if (ss.size() == n - 1){
            max_sub.push_back(ss);
        }
    }

    int tmp = 0;
    for(auto &ss : sub){
        if(max_sub[0].substr(0, ss.size()) == ss){
            ++tmp;
        }
    }
    if(tmp < n - 1 || string(max_sub[0], 1, n - 2) != string(max_sub[1], 0, n - 2)){
        swap(max_sub[0], max_sub[1]);
    }
    str = max_sub[0] + max_sub[1].back();

    for(int i = 0; i < sub.size(); ++i){
        cout << get_ans(sub[i], str);
    }
    cout << endl;
    return 0;
}