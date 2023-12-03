#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    ll grass[n];
    for (ll i = 0; i < n; ++i) {
        cin >> grass[i];
        if (i > 0) {
            grass[i] += grass[i - 1];
        }
    }
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;

        ll ans = 0;
        ll left = a, right = n - 1;
        while (left <= right) {
            ll mid = (right + left) / 2;
            if (grass[mid] - (a > 0 ? grass[a - 1] : 0) + (mid - a + 1) * k > b) {
                right = mid - 1;
            } else {
                ans = grass[mid] - (a > 0 ? grass[a - 1] : 0);
                left = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}