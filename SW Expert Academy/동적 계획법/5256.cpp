#include <iostream>
#include <vector>

using namespace std;

const int MAX = 70;

vector<vector<int>> binomialCoeff() {
    vector<vector<int>> dp (MAX+1, vector<int> (MAX+1, 1));
    for(int i = 2; i <= MAX; i++) {
        for(int j = 1; j <= i-1; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp;
}

int main() {
    int t, n, a, b;
    vector<vector<int>> coef = binomialCoeff();

    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> a >> b;
        cout << '#' << i << ' ' << coef[n][a] << '\n';
    }
    return 0;
}