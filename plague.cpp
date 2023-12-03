#include <bits/stdc++.h>
using namespace std;

int r, c, T;
int arr[505][505];

void corona(int R, int C, int day, int& count) {
    if (R >= r || R < 0 || C >= c || C < 0 || arr[R][C] == 2 || day > T) {
        return;
    }
    if (day + 3 < arr[R][C] || arr[R][C] == 0) {
        if (arr[R][C] == 0) ++count;
        arr[R][C] = day + 3;
        corona(R + 1, C, day + 1, count);
        corona(R - 1, C, day + 1, count);
        corona(R, C + 1, day + 1, count);
        corona(R, C - 1, day + 1, count);
    }
}

int main() {
    cin >> r >> c >> T;
    int count = 0;
    vector<pair<int, int>> drop;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int in;
            cin >> in;
            if (in == 2) {
                arr[i][j] = 2;
            }
            if (in == 1) {
                drop.push_back({i, j});
            }
        }
    }
    for (auto i : drop) {
        corona(i.first, i.second, 0, count);
    }
    cout << count;
}