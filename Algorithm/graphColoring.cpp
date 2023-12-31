#include <bits/stdc++.h>
using namespace std;

int nattee(const vector<set<int>>& vec, int n) {
    vector<int> color(n, 0);
    int maxN = 0;
    for (int i = 0; i < n; ++i) {
        int c = 1;
        for (auto adj : vec[i]) {
            if (c == color[adj]) {
                c++;
            }
        }

        color[i] = c;
        maxN = max(maxN, c);
        if (maxN == 8) ++maxN;
    }

    return maxN;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<set<int>> vec(n);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        vec[a].insert(b);
        vec[b].insert(a);
    }
    cout << nattee(vec, n);
}

/*
15 90
0 6
6 11
5 13
6 10
7 10
3 12
5 14
10 11
12 14
6 14
8 9
1 8
3 6
6 9
9 14
3 9
7 9
3 5
9 13
3 10
5 10
2 8
0 7
0 12
4 14
1 9
0 2
1 14
2 5
11 14
5 6
5 8
2 13
6 8
2 3
0 10
4 6
0 1
6 13
3 8
2 11
1 4
4 5
1 2
8 11
0 5
1 13
1 6
0 9
5 9
11 12
2 14
3 11
0 3
3 4
2 9
11 13
4 11
0 14
2 6
10 13
9 12
6 12
9 11
0 4
8 12
5 7
2 7
0 11
1 11
10 12
4 9
1 5
5 11
13 14
3 14
1 12
3 7
7 11
4 12
8 13
0 13
8 10
4 7
7 8
12 13
3 13
4 13
6 7
4 8
*/