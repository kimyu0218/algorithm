#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> dp (n, vector<int> (m, 0));
    
    dp[0][0] = board[0][0];
    for(int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + board[0][j];
    }
    
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + board[i][0];
        for(int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    int n, m;
    vector<vector<int>> board;
    
    cin >> n >> m;
    
    board.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << solution(board);
    return 0;
}