#include <bits/stdc++.h>
using namespace std;

long long vec[100005];

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    long long n,m,start;
    cin >> n >> m >> start;
    
    for(long long i = 0 ; i < n ; ++i){
        long long day,money;
        cin >> day >> money;
        vec[day] = money;
    }
    vec[0] = start;

    long long save = start;
    for(int i = 1 ; i < 100005 ; ++i){
        if(vec[i] != 0){
            save = vec[i];
        }
        vec[i] = save+ vec[i-1];
    }

    
    for(long long i = 0 ; i < m ; ++i){
        long long price,scam;
        cin >> price >> scam;
        if(vec[scam] >= price){
            cout << lower_bound(vec, vec+100005 , price) - vec << " ";
        }
        else{
            cout << lower_bound(vec, vec+100005 , price+vec[scam]) - vec << " ";
        }
        
    }

}