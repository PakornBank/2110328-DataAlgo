#include <bits/stdc++.h>
using namespace std;

void permutation(int n, int m, string str, string ones, set<string>& s) {
    if (str.length() == n - m) {
        for (int i = 0; i <= n - m; ++i) {
            string temp = str;
            temp.insert(i, ones);
            s.insert(temp);
        }
        return;
    }
    permutation(n, m, str + "0", ones, s);
    permutation(n, m, str + "1", ones, s);
}

int main() {
    int n, m;
    cin >> n >> m;
    set<string> s;
    string ones = "";
    for (int i = 0; i < m; ++i) {
        ones += "1";
    }
    permutation(n, m, "", ones, s);
    for (auto i : s) {
        cout << i << endl;
    }
}