#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    vector<int> count(4, 0);
    unsigned long long ans = 0;

    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        arr[i] = input;
        ++count[input];
    }

    for (int i = 0; i < count[1]; ++i) {
        if (arr[i] != 1) {
            ++ans;
        }
    }

    for (int i = count[1]; i < count[1] + count[2]; ++i) {
        if (arr[i] == 3) {
            ++ans;
        }
    }
    cout << ans;
}