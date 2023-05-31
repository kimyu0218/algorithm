class Solution {
public:
    typedef pair<int, int> pi;
    int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

    int bfs(int row, int col, int n, int m, vector<vector<int>> &grid) {
        int area = 0;
        queue<pi> q;

        q.push({row, col});
        grid[row][col] = 2;

        while(!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            area++;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int new_row = row + dr[i];
                int new_col = col + dc[i];

                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == 1) {
                    q.push({new_row, new_col});
                    grid[new_row][new_col] = 2;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int answer = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    answer = max(answer, bfs(i, j, n, m, grid));
                }
            }
        }
        return answer;
    }
};