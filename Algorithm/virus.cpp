#include <bits/stdc++.h>
using namespace std;

bool isVirus(string str, int k) {
    if (k == 1) {
        return (str[0] == '0' && str[1] == '1');
    }

    string left = str.substr(0, 1 << (k - 1)), right = str.substr(1 << (k - 1), str.length());
    string reverseLeft = left;
    reverse(reverseLeft.begin(), reverseLeft.end());
    return (isVirus(left, (k - 1)) || isVirus(reverseLeft, (k - 1))) && isVirus(right, k - 1);
}

int main() {
    int n, k;
    cin >> n >> k;
    cin.ignore();
    while (n--) {
        string str;
        getline(cin, str);
        stringstream ss(str);
        string c;
        str = "";
        while (getline(ss, c, ' ')) {
            str += c;
        }
        isVirus(str, k) ? cout << "yes" : cout << "no";
        cout << endl;
    }
}