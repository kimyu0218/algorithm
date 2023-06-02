class Solution {
public:
    int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

    bool backtracking(int row, int col, int n, int m, int idx, string &word, vector<vector<bool>> &visited, vector<vector<char>> &board) {
        if(idx == word.length()) {
            return true;
        }

        for(int i = 0; i < 4; i++) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];
            if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= m) {
                continue;
            }
            if(board[new_row][new_col] == word[idx] && !visited[new_row][new_col]) { // next character
                visited[new_row][new_col] = true;
                if(backtracking(new_row, new_col, n, m, idx+1, word, visited, board)) {
                    return true;
                }
                visited[new_row][new_col] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited (n, vector<bool> (m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if(backtracking(i, j, n, m, 1, word, visited, board)) {
                        return true;
                    }
                    visited[i][j] = false;
                }

            }
        }
        return false;
    }
};