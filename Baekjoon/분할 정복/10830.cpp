#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<int>> matrix;
const int MOD = 1000;
matrix a;

matrix combine(int n, matrix m1, matrix m2) {
    matrix result (n, vector<int> (n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++)
                result[i][j] += (m1[i][k] * m2[k][j]);
            result[i][j] %= MOD;
        }
    }
    return result;
}

matrix divide(int n, ll b) {
    if(b == 1) return a; // conquer

    // divide & combine
    if(b % 2 == 0) {
        matrix sub = divide(n, b/2);
        return combine(n, sub, sub);
    }
    return combine(n, a, divide(n, b-1));
}

int main() {
    int n;
    ll b;
    cin >> n >> b;

    a.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) { // A 입력
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    matrix ans = divide(n, b);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << ans[i][j] % MOD << ' ';
        cout << '\n';
    }
    return 0;
}