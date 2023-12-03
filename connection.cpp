#include <bits/stdc++.h>
using namespace std;

int BFS(int start, vector<vector<int>> adj, int k) {
    int count = 0;
    vector<int> dist(adj.size(), -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    ++count;
    while (q.size() > 0) {
        int u = q.front();
        if (dist[u] >= k) break;
        q.pop();
        for (int b : adj[u]) {
            if (dist[b] == -1) {
                dist[b] = dist[u] + 1;
                ++count;
                q.push(b);
            }
        }
    }
    return count;
}

int nattee(vector<vector<int>> adj, int k) {
    int Max = INT_MIN;
    int n = adj.size();
    for (int i = 0; i < n; ++i) {
        Max = max(BFS(i, adj, k), Max);
    }
    return Max;
}

int main() {
    int n, e, k;
    cin >> n >> e >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << nattee(adj, k);
}