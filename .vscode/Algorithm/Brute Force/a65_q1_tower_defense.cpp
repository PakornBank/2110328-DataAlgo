#include <bits/stdc++.h>
using namespace std;

int main() {
    int pathLen, monsterAmt, towerAmt, towerRange;
    cin >> pathLen >> monsterAmt >> towerAmt >> towerRange;

    vector<int> path(pathLen, 0);

    int monsterPos[monsterAmt];
    for (int i = 0; i < monsterAmt; ++i) {
        int pos;
        cin >> pos;
        monsterPos[i] = pos;
    }

    unsigned long long totalPow = 0;

    int monsterPow[monsterAmt];
    for (int i = 0; i < monsterAmt; ++i) {
        int pow;
        cin >> pow;
        monsterPow[i] = pow;
        totalPow += pow;
    }

    for (int i = 0; i < monsterAmt; ++i) {
        path[monsterPos[i]] = monsterPow[i];
    }

    multiset<pair<int, int>> tower;
    for (int i = 0; i < towerAmt; ++i) {
        int pos;
        cin >> pos;
        int totalTargetPower = 0;
        for (int j = pos - towerRange; j <= pos + towerRange; ++j) {
            if (j < 0) {
                j = 0;
            }
            if (j > pathLen) {
                break;
            }
            totalTargetPower += path[j];
        }
        tower.insert({totalTargetPower, pos});
    }

    for (auto i : tower) {
        for (int j = i.second - towerRange; j <= i.second + towerRange; ++j) {
            if (j < 0) {
                j = 0;
            }
            if (j > pathLen) {
                break;
            }
            if (path[j] > 0) {
                --path[j];
                --totalPow;
                break;
            }
        }
    }

    cout << totalPow;
}