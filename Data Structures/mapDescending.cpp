#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    auto compare = [](const double& lhs, const double& rhs){
        return rhs < lhs;
    };
    map<double,double,decltype(compare)> m(compare);
    m.insert({10,9});
    m.insert({6,7});
    m.insert({8,5});
    for(auto it : m){
        cout << it.first << " " << it.second << endl;
    }

    set<double, decltype(compare)> s(compare);
    s.insert(10);
    s.insert(9);
    s.insert(20);
    for(auto it : s){
        cout << it << endl;
    }
}