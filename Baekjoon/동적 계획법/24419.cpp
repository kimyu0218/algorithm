#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

const int N = 1e3;
const int MOD = 1e9 + 7;

int dr[2] = { 0, 1 };
int dc[2] = { 1, 0 };
int matrix[N][N];

pi solution(int n) {
    vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[0][i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    return { dp[n][n], n * n };
}

int main() {
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    pi result = solution(n);
    
    cout << result.first << ' ' << result.second;
    return 0;
}