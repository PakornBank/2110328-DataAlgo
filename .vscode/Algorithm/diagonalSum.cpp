#include <bits/stdc++.h>
using namespace std;

int MSS(const vector<vector<int>>& vec, int row, int column) {
    int size = vec.size();
    int suf = vec[row][column], mss = vec[row][column];
    ++row;
    ++column;
    while (row < size && column < size) {
        suf = max(vec[row][column], suf + vec[row][column]);
        mss = max(mss, suf);
        ++row;
        ++column;
    }
    return mss;
}

int findMax(const vector<vector<int>>& vec) {
    int Max = INT_MIN;
    int size = vec.size();
    for (int i = 0; i < size; ++i) {
        Max = max(MSS(vec, 0, i), Max);
    }
    for (int i = 1; i < size; ++i) {
        Max = max(MSS(vec, i, 0), Max);
    }
    return Max;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> vec[i][j];
        }
    }
    cout << findMax(vec);
}