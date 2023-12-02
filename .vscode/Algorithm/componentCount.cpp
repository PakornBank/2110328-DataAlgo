#include <bits/stdc++.h>
using namespace std;

void dfs(const int& node, const vector<vector<int>>& adjList, const int& v, vector<bool>& visited) {
    visited[node] = true;
    for (auto adj : adjList[node]) {
        if (!visited[adj]) {
            dfs(adj, adjList, v, visited);
        }
    }
    return;
}

int componentCount(const vector<vector<int>>& adjList, int v) {
    int count = 0;
    vector<bool> visited(v + 1, false);
    for (int i = 1; i <= v; ++i) {
        if (!visited[i]) {
            dfs(i, adjList, v, visited);
            ++count;
        }
    }
    return count;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adjList(v + 1);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    cout << componentCount(adjList, v);
}