#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a;
    cin >> n >> a;
    ll T[n];

    for (ll i = 0; i < n; ++i) {
        cin >> T[i];
    }

    for (ll i = 0; i < a; ++i) {
        ll number;
        cin >> number;
        ll ans = 0;
        ll l = 0, r = 10000000000000000;
        while (l <= r) {
            ll m = (l + r) / 2;
            ll t = 0;
            for (ll j = 0; j < n; ++j) {
                t += m / T[j] + 1;
            }

            if (t >= number) {
                ans = m;
                r = m - 1;
            } else
                l = m + 1;
        }
        cout << ans << "\n";
    }
}
