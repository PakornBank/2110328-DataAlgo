#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    long long n,m,start;
    cin >> n >> m >> start;
    map<long long , long long> mmap;
    mmap[0] = start;
    for(long long i = 0 ; i < n ; ++i){
        long long day , money;
        cin >> day >> money;
        mmap[day] = money;
    }
    for(long long i = 0 ; i < m ; ++i){
        long long price,scam;
        cin >> price >> scam;
        long long money = 0;
        long long beforeMoney = 0;
        auto it = mmap.begin();
        long long date = 0;
        auto end = mmap.end();
        --end;
        while(money < price){
            date = it->first;
            
            
            if(it != end){
                beforeMoney = money;
                ++it;
            }

            money += max(mmap[date],mmap[date] * (it->first - date)); // เงินเก็บด้วยอัตราปัจจุบันจนรอบถัดไป   

        }
        long long dateCount = date;
        while(price > beforeMoney){
            beforeMoney += mmap[date];
            dateCount++;
        }
        cout << dateCount - 1 << " ";
    }


}
/**/