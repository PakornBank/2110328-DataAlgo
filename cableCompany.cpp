#include <bits/stdc++.h>
using namespace std;

int msp(vector<vector<pair<int, int>>> vec) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(vec.size(), false);
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int weight = it.first;

        if (visited[node]) continue;
        visited[node] = true;
        sum += weight;

        for (auto i : vec[node]) {
            if (!visited[i.second]) {
                pq.push(i);
                if (node == 0) {
                }
            }
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> vec(n);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a;
            cin >> a;
            vec[j].push_back({a, i});
            vec[i].push_back({a, j});
        }
    }
    cout << msp(vec);
}