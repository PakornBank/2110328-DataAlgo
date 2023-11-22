#include <iostream>
#include <unordered_map>

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    long long n,m;
    std::unordered_map <long long, long long> sonFather;
    std::cin >> n >> m;
    for(long long i = 0 ; i < n ; ++i){
        long long f , s;
        std::cin >> f >> s;
        sonFather[s] = f;
    }
    for(long long i = 0 ; i < m ; ++i){
        long long a , b;
        std::cin >> a >> b;
        if(a != b && sonFather[sonFather[a]] > 0 && sonFather[sonFather[b]] > 0 &&sonFather[sonFather[a]] == sonFather[sonFather[b]]){
            std::cout << "YES";
        }
        else std::cout << "NO";

        std::cout << std::endl;
    }
}