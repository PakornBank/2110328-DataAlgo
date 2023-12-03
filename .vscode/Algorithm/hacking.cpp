#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(int n, vector<vector<int>>& dist) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    vector<int> start;
    for (int i = 0; i < k; ++i) {
        int in;
        cin >> in;
        start.push_back(in);
    }

    int timeToHack[n];
    for (int i = 0; i < n; ++i) {
        cin >> timeToHack[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        dist[a][a] = 0;
        dist[b][b] = 0;
        dist[a][b] = timeToHack[b];
        dist[b][a] = timeToHack[a];
    }
    floyd_warshall(n, dist);
    int ans = 0;

    for (int j = 0; j < n; ++j) {
        int Min = INT_MAX;
        for (auto i : start) {
            Min = min(Min, dist[i][j] + timeToHack[i]);
        }
        ans = max(Min, ans);
    }
    cout << ans;
}