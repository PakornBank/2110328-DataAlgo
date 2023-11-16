#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    unordered_map <long long , bool> m;
    cin >> n;
    for(long long i = 0 ; i < n ; ++i){
        long long num;
        cin >> num;
        if(!m[num] && num > 0 && num <= n){
            m[num] = true;
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}