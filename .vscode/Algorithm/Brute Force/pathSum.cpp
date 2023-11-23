#include <bits/stdc++.h>
using namespace std;

int maxW[25];

unsigned long long maxSum = 0;

int adj[25][25];

void nattee(int cap,
            vector<bool>& visited, int curNode, int curSum,
            int goal, bool& found) {
    if (curSum == goal) {
        found = true;
        return;
    }
    if (curSum > goal || curSum + cap < goal) {
        return;
    }
    visited[curNode] = true;
    for (int i = 0; i < 25; ++i) {
        if (adj[curNode][i] && !visited[i]) {
            nattee(cap - maxW[i], visited, i, curSum + adj[curNode][i], goal, found);
            if (found) return;
        }
    }
    visited[curNode] = false;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int k[8];

    for (auto& i : k) {
        int input;
        cin >> input;
        i = input;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = adj[b][a] = w;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            maxW[i] = max(maxW[i], adj[i][j]);
        }
        maxSum += maxW[i];
    }

    for (auto i : k) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            vector<bool> visited(25, false);
            nattee(maxSum - maxW[j], visited, j, 0, i, found);
            if (found) {
                cout << "YES";
                break;
            }
        }
        if (!found) cout << "NO";
        cout << endl;
    }
}

/*
16 80
5467 3353 5769 2893 1 2117 2941 2564
11 14 372
0 15 201
7 10 384
7 15 73
1 2 100
1 10 165
0 12 347
9 10 128
3 12 240
2 11 459
0 1 111
2 8 125
0 14 193
2 14 360
5 14 13
1 7 427
0 11 256
12 14 399
2 7 311
5 12 380
4 5 12
1 5 239
13 15 351
6 7 484
14 15 28
4 15 397
2 5 9
0 4 159
3 9 194
8 10 364
3 14 79
4 7 206
6 8 427
0 7 438
3 6 216
1 14 444
3 15 479
7 12 163
0 13 37
13 14 66
6 12 202
2 15 197
9 12 225
7 13 4
1 4 321
2 3 470
2 12 265
6 11 270
0 10 34
8 11 19
1 6 357
11 13 127
7 9 97
6 13 465
0 5 130
0 9 71
5 9 81
2 6 96
3 10 284
1 8 251
5 11 474
8 14 283
8 12 304
5 15 468
4 9 344
3 7 250
3 4 230
6 15 401
3 13 97
11 12 304
4 10 121
3 5 223
4 12 254
3 8 204
9 15 499
1 13 196
5 7 468
8 13 477
2 9 330
12 15 248
*/