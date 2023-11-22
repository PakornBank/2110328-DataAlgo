#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a;
    cin >> n >> a;
    long long i = 1;
    size_t child = a;
    vector<long long> v;
    while (child < n) {
        for (long long j = 0; j < i; ++j) {
            if (child + j >= n) break;
            v.push_back(child + j);
        }
        child = 2 * child + 1;
        if (child >= n) break;
        i *= 2;
    }
    cout << v.size() << endl;
    for (auto i : v) {
        cout << i << " ";
    }
}
