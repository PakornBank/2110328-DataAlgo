#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int n , m, k ;
    cin >> n >> m >> k;
    vector<long long> data;
    for(int i = 0 ; i < n ; ++i){
        long long num;
        cin >> num;
        data.push_back(num);
    }
    sort(data.begin() , data.end());
    for(int i = 0 ; i < m ; ++i){
        long long num;
        cin >> num;
        cout << upper_bound(data.begin() , data.end() , num + k) - lower_bound(data.begin() , data.end() , num - k) << " ";
    }
}