class Solution {
public:
    typedef pair<int, int> pi;
    int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

    void bfs(int row, int col, int n, int m, vector<vector<char>> &grid) {
        queue<pi> q;

        q.push({row, col});
        grid[row][col] = '2';

        while(!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int new_row = row + dr[i];
                int new_col = col + dc[i];
                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == '1') {
                    q.push({new_row, new_col});
                    grid[new_row][new_col] = '2';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, n, m, grid);
                }
            }
        }
        return cnt;
    }
};