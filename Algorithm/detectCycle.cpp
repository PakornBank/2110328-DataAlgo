#include <bits/stdc++.h>
using namespace std;

bool DFS(const int& start, const vector<vector<int>>& adj, vector<bool>& visited, const int& parent) {
    visited[start] = true;
    for (auto i : adj[start]) {
        if (i != parent) {
            if (visited[i] || DFS(i, adj, visited, start)) {
                return true;
            }
        }
    }
    return false;
}

bool detectCircuit(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (DFS(i, adj, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> adj(n);
        while (e--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout << (detectCircuit(adj) ? "YES" : "NO") << endl;
    }
}