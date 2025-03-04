#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int dr[2] = { 0, 1 };
int dc[2] = { 1, 0 };

ll solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<ll>> dp (n, vector<ll> (n, 0));
    
    dp[0][0] = 1;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            if(!board[r][c]) {
                continue;
            }
            for(int i = 0; i < 2; i++) {
                int nr = r + dr[i] * board[r][c];
                int nc = c + dc[i] * board[r][c];
                
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) {
                    continue;
                }
                dp[nr][nc] += dp[r][c];
            }
        }
    }
    return dp[n - 1][n - 1];
}

int main() {
    int n;
    vector<vector<int>> board;
    
    cin >> n;
    
    board.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << solution(board);
    return 0;
}