#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll n1 = 3, n0 = 1;
    while (n--) {
        ll temp = n1;
        n1 = (2 * n1 + n0) % 100000007;
        n0 = temp % 100000007;
    }
    cout << n0;
}
