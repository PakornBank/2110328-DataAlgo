#include <bits/stdc++.h>
using namespace std;

int main() {
    double w;
    int n;
    cin >> w >> n;
    double W[n];
    double V[n];
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> W[i];
    }
    priority_queue<pair<double, double>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({V[i] / W[i], W[i]});
        // cout << V[i] / W[i] << endl;
    }
    double ans = 0;
    while (w > 0) {
        double value = pq.top().first, weight = pq.top().second;
        pq.pop();
        if (w >= weight) {
            w -= weight;
            ans += value * weight;
        } else {
            ans += value * w;
            w = 0;
        }
    }
    printf("%.4lf", ans);
}