#include <bits/stdc++.h>
using namespace std;

bool dfs(const vector<vector<int>>& vec, int node, int parent, vector<bool>& visited) {
    visited[node] = true;
    if (vec[node].size() > 2) {
        return false;
    }
    if (vec[node].size() == 0) {
        return true;
    }
    for (auto adj : vec[node]) {
        if (adj != parent) {
            if (visited[adj] == true) {  // visited the visited graph
                return false;
            }
            if (!dfs(vec, adj, node, visited)) {
                return false;
            }
        }
    }
    return true;
}

int count(int v, const vector<vector<int>>& vec) {
    vector<bool> visited(v, false);

    int ans = 0;

    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            if (dfs(vec, i, -1, visited)) {
                // cout << i;
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> vec(v);

    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    cout << count(v, vec);
}
