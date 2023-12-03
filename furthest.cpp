#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void nattee(const vector<vector<ll>>& arr, vector<ll>& dist) {
    dist[0] = 0;
    ll n = dist.size();
    for (ll cnt = 0; cnt < n - 1; ++cnt) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                if (arr[i][j] == -1) {
                    continue;
                }
                if (dist[j] > dist[i] + arr[i][j]) {
                    dist[j] = dist[i] + arr[i][j];
                }
            }
        }
    }
}

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(n, -1));

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<ll> dist(n, 1e18);

    nattee(arr, dist);

    ll ans = *max_element(dist.begin(), dist.end());
    if (ans > 1e15) {
        cout << -1;
        return 0;
    }
    cout << ans;
}