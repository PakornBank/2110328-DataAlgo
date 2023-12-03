#include <bits/stdc++.h>
using namespace std;

int DFS(const vector<vector<int>>& adj, const int& node, const int& parent, vector<int>& distance) {
    if (parent != -1) {
        distance[node] = distance[parent] + 1;
    } else {
        distance[node] = 0;
    }
    for (auto i : adj[node]) {
        if (i != parent) {
            if (distance[i] != -1) {
                return distance[node] - distance[i] + 1;
            }
            int ans = DFS(adj, i, node, distance);

            if (ans > -1) {
                return ans;
            }
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> distance(n, -1);
    cout << DFS(adj, 0, -1, distance);
}
