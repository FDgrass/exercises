#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        for(int i = 0, j = 0; i < n; ++i, ++j, j %= k){
            cout << (char)('a' + j);
        }
        cout << endl;
    }
}