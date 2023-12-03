#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll chocolate[10005];
set<int> s;

ll nattee(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (chocolate[n] > 0) {
        return chocolate[n];
    }
    for (auto i : s) {
        chocolate[n] += nattee(n - i);
        chocolate[n] %= 1000003;
    }
    return chocolate[n];
}

int main() {
    int n, k;
    cin >> n >> k;
    chocolate[1] = 1;
    for (int i = 0; i < k; ++i) {
        int input;
        cin >> input;
        s.insert(input);
    }

    cout << nattee(n);
}