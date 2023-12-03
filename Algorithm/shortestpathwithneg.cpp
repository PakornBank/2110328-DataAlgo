#include <bits/stdc++.h>
using namespace std;

vector<int> dist(105, 1e6);  // careful with using INT_MAX, it may cause overflow

bool isNegBellmanFordRanger(vector<vector<pair<int, int>>> adj, int s) {
    int n = adj.size();
    dist[s] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto adjList : adj[j]) {
                int a = j, b = adjList.first, w = adjList.second;
                if (dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                }
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        for (auto adjList : adj[j]) {
            int a = j, b = adjList.first, w = adjList.second;
            if (dist[b] > dist[a] + w) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N, E, s;
    cin >> N >> E >> s;
    vector<vector<pair<int, int>>> adj(N);  // pair as adj node and weight
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    if (isNegBellmanFordRanger(adj, s)) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        cout << dist[i] << " ";
    }
}