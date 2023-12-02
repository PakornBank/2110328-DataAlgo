#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;

vector<int> nmModK(const vector<int>& n, const vector<int>& m) {
    vector<int> vec(4);
    vec[0] = (n[0] * m[0] + n[1] * m[2]) % k;
    vec[1] = (n[0] * m[1] + n[1] * m[3]) % k;
    vec[2] = (n[2] * m[0] + n[3] * m[2]) % k;
    vec[3] = (n[2] * m[1] + n[3] * m[3]) % k;
    return vec;
}

vector<int> nattee(const vector<int>& matrix, ll n) {
    if (n == 1) return matrix;
    vector<int> vec = nattee(matrix, n / 2);
    if (n % 2 == 0) {
        return nmModK(vec, vec);
    } else
        return nmModK(matrix, nmModK(vec, vec));
}

int main() {
    ll n;
    cin >> n >> k;
    vector<int> matrix(4);
    for (auto& i : matrix) {
        cin >> i;
    }
    for (auto i : nattee(matrix, n)) {
        cout << i << " ";
    }
}