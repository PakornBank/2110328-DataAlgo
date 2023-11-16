#include <bits/stdc++.h>
using namespace std;

void boom(list<long long>& lis, list<long long>::iterator it) {
    auto itFront = it;
    auto itBack = it;
    long long count = 0;
    long long val = *it;
    while (*(itFront) == *it) {
        ++count;
        if (itFront == lis.begin()) {
            break;
        }
        --itFront;
    }
    if (*itFront != *it) {
        ++itFront;
    }

    while (*(itBack) == *it && itBack != lis.end()) {
        ++count;
        ++itBack;
    }
    --count;

    if (count >= 3) {
        while (count--) {
            itFront = lis.erase(itFront);
        }
        if (itFront != lis.begin() && itFront == --itFront) {
            boom(lis, itFront);
        }
    }
}

int main() {
    list<long long> lis;
    long long n, k, v;
    cin >> n >> k >> v;
    for (int i = 0; i < n; ++i) {
        long long ball;
        cin >> ball;
        lis.push_back(ball);
    }
    auto it = lis.begin();
    while (k--) {
        ++it;
    }
    it = lis.insert(it, v);
    boom(lis, it);
    for (auto i : lis) {
        cout << i << " ";
    }
}