class Solution {
public:
    vector<int> check; // check[col] = row

    bool possible(int num) {
        int idx = 0;
        while(idx < num) {
            // 1. duplicate row
            // 2. duplicate cross
            if(check[idx] == check[num] || abs(check[num] - check[idx]) == (num - idx)) {
                return false;
            }
            idx++;
        }
        return true;
    }

    void backtracking(int col, int n, vector<vector<string>> &answer) {
        if(col == n) { // N-Queen complete
            string blank = "";
            for(int i = 0; i < n; i++) {
                blank += ".";
            }
            vector<string> board (n, blank);
            for(int i = 0; i < n; i++) { // i : col
                int row = check[i];
                board[row][i] = 'Q';
            }
            answer.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++) {
            check[col] = i;
            if(possible(col)) {
                backtracking(col+1, n, answer);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        check.assign(n, 0);
        backtracking(0, n, answer);
        return answer;
    }
};