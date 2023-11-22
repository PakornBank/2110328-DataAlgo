#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> vec(3, false);
    vec = -vec;
    for (auto i : vec) {
        cout << i << endl;
    }
}