#include <bits/stdc++.h>
using namespace std;

void bellman_ford(const vector<vector<pair<int, int>>>& vec, int s, int ini, vector<int>& dist) {
    if (ini >= dist[s]) {
        return;
    }
    int n = vec.size();

    queue<int> toUpdate;
    toUpdate.push(s);

    dist[s] = ini;
    for (int it = 1; it < n; ++it) {
        bool isIncreased = false;
        while (!toUpdate.empty()) {
            int update = toUpdate.front();
            toUpdate.pop();
            for (auto j : vec[update]) {
                if (dist[j.first] > dist[update] + j.second) {
                    dist[j.first] = dist[update] + j.second;
                    toUpdate.push(j.first);
                    isIncreased = true;
                }
            }
        }
        if (!isIncreased) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
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

    vector<vector<pair<int, int>>> vec(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back({b, timeToHack[b]});
        vec[b].push_back({a, timeToHack[a]});
    }
    int ans = 0;
    vector<int> dist(n, 1e9);
    for (auto i : start) {
        bellman_ford(vec, i, timeToHack[i], dist);
    }
    for (int i = 0; i < n; ++i) {
        ans = max(dist[i], ans);
    }
    cout << ans;
}