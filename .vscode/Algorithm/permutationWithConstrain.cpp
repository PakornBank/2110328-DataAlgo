#include <bits/stdc++.h>
using namespace std;

void nattee(vector<int>& toPrint, const int& n, const vector<int>& constrain, vector<bool> inserted) {
    if (toPrint.size() == n) {
        for (auto i : toPrint) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!inserted[i]) {
            if (constrain[i] != -1 && !inserted[constrain[i]]) {  // if there is constrain, but it wasn't inserted yet, skip
                continue;
            }
            toPrint.push_back(i);
            inserted[i] = true;
            nattee(toPrint, n, constrain, inserted);
            toPrint.pop_back();
            inserted[i] = false;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> constrain(n, -1);  // -1 is no constrain
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        constrain[b] = a;  // before inserting b, a should already been inserted
    }
    vector<int> toPrint(0);
    vector<bool> inserted(n, false);
    nattee(toPrint, n, constrain, inserted);
}