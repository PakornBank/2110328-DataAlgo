#include <bits/stdc++.h>
using namespace std;

int main() {
    double w;
    int n;
    cin >> w >> n;
    vector<double> W(n), V(n);
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> W[i];
    }
    // Priority queue to store the value-to-weight ratio and actual value
    priority_queue<pair<double, pair<double, double>>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({V[i] / W[i], {V[i], W[i]}});
    }
    double ans = 0;
    while (w > 0 && !pq.empty()) {
        auto top = pq.top();
        pq.pop();
        double value_per_unit = top.first;
        double value = top.second.first;
        double weight = top.second.second;

        if (w >= weight) {
            w -= weight;
            ans += value;  // Use actual value here
        } else {
            ans += value_per_unit * w;  // Use value per unit * remaining weight
            w = 0;
        }
    }
    printf("%.4lf\n", ans);
    return 0;
}
