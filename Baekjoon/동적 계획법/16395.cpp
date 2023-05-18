#include <iostream>
#include <vector>

using namespace std;

int pascalTriangle(int n, int k) {
    if(k == 0 || k == n) {
        return 1;
    }
    vector<vector<int>> dp(n, vector<int> (n, 1));
    for(int i = 2; i < n; i++) {
        for(int j = 1; j <= i-1; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n-1][k-1];
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << pascalTriangle(n, k);
    return 0;
}