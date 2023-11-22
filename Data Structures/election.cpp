#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    map<string, long long> mmap;
    for (long long i = 0; i < n; ++i)
    {
        string name;
        cin >> name;
        mmap[name]++;
    }
    map<long long, string> mmap2;
    for (auto i : mmap)
    {
        mmap2.insert({i.second, i.first});
    }
    long long count = 1;
    auto idx = mmap2.end();
    idx--;
    while (idx != mmap2.begin() && count < k)
    {
        count++;
        idx--;
    }
    cout << idx->first;
}