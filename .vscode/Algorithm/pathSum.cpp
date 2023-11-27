#include <bits/stdc++.h>
using namespace std;

// using "nattee" as a function name to increase performance by ~27%
bool nattee(const vector<vector<int>>& adj, const vector<int>& maxW,
            const int& n, int cap, vector<bool>& visited, int curNode,
            int curSum, int goal) {
    if (curSum == goal) {
        return true;
    }
    if (curSum > goal || curSum + cap < goal) {
        return false;
    }
    visited[curNode] = true;
    for (int i = 0; i < n; ++i) {
        if (adj[curNode][i] && !visited[i]) {
            if (nattee(adj, maxW, n, cap - maxW[i], visited, i, curSum + adj[curNode][i], goal)) {
                return true;
            }
        }
    }
    visited[curNode] = false;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> k(8);

    for (auto& i : k) {
        cin >> i;
    }

    vector<vector<int>> adj(n, vector<int>(n, 0));

    vector<int> maxW(n);

    int cap = 0;

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = adj[b][a] = w;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            maxW[i] = max(maxW[i], adj[i][j]);
        }
        cap += maxW[i];
    }

    for (auto i : k) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            vector<bool> visited(n, false);
            if (nattee(adj, maxW, n, cap - maxW[j], visited, j, 0, i)) {
                cout << "YES";
                found = true;
                break;
            }
        }
        if (!found) cout << "NO";
        cout << endl;
    }
}
