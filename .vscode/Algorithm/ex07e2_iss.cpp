#include <bits/stdc++.h>
using namespace std;

void increasingSum(const int& num, const int& currentTotal, const int& prevNum, unsigned long long& count) {
    if (currentTotal == num) {
        ++count;
        return;
    }
    if (currentTotal + prevNum > num) {
        return;
    }
    for (int i = prevNum; i <= num; ++i) {
        increasingSum(num, currentTotal + i, i, count);
    }
}

int main() {
    int n;
    cin >> n;
    unsigned long long count = 0;
    increasingSum(n, 0, 1, count);
    cout << count;
}