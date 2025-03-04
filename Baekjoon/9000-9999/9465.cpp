#include <iostream>
#include <vector>

using namespace std;

int maxScore(int n, vector<vector<int>> &board) {
    vector<vector<int>> dp(2, vector<int> (n, 0));
    dp[0][0] = board[0][0]; // 맨 왼쪽 윗줄 스티커 붙이기
    dp[1][0] = board[1][0]; // 맨 왼쪽 아랫줄 스티커 붙이기

    for(int i = 1; i < n; i++) { // i번째 열
        // 윗쪽 : 스티커 붙이지 않기 or 스티커 붙이기
        dp[0][i] = max(dp[0][i-1], dp[1][i-1] + board[0][i]);
        // 아랫쪽 : 스티커 붙이지 않기 or 스티커 붙이기
        dp[1][i] = max(dp[1][i-1], dp[0][i-1] + board[1][i]);
    }
    return max(dp[0][n-1], dp[1][n-1]);
}

int main() {
    int t, n;
    vector<vector<int>> board;

    cin >> t;
    while(t--) {
        cin >> n;
        board.assign(2, vector<int> (n, 0));
        for(int i = 0; i < 2; i++) { // 스티커 점수 입력
            for(int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }
        cout << maxScore(n, board) << '\n';
    }
    return 0;
}