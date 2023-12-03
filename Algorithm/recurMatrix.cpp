#include <bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>>& vec, int a, int b, int top, int bottom, int left, int right) {
    if (a == 0) {
        vec[top][left] = b;
        return;
    }
    recur(vec, a - 1, b, top, (top + bottom) / 2, left, (left + right) / 2);
    recur(vec, a - 1, b - 1, top, (top + bottom) / 2, (left + right) / 2, right);
    recur(vec, a - 1, b + 1, (top + bottom) / 2, bottom, left, (left + right) / 2);
    recur(vec, a - 1, b, (top + bottom) / 2, bottom, (left + right) / 2, right);
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> matrix(1 << a, vector<int>(1 << a));
    recur(matrix, a, b, 0, 1 << a, 0, 1 << a);
    for (auto i : matrix) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}