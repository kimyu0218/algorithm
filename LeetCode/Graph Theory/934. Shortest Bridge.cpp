class Solution {
public:
    typedef pair<int, int> pi;
    int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

    void dfs(int row, int col, int n, vector<vector<int>> &grid) { // find second island
        grid[row][col] = 2;

        for(int i = 0; i < 4; i++) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < n && grid[new_row][new_col] == 1) {
                dfs(new_row, new_col, n, grid);
            }
        }
    }

    int bfs(int row, int col, int n, vector<vector<int>> &grid) {
        vector<vector<int>> step(n, vector<int> (n, 0));
        queue<pi> q;

        step[row][col] = 1;
        q.push({row, col});

        while(!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int new_row = row + dr[i];
                int new_col = col + dc[i];

                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < n && !step[new_row][new_col]) {
                    if(grid[new_row][new_col] == 2) {
                        return step[row][col];
                    }
                    if(grid[new_row][new_col] == 0) {
                        step[new_row][new_col] = step[row][col] + 1;
                        q.push({new_row, new_col});
                    }
                }
            }
        }
        return -1; // cannot find second island
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n*n; i++) { // find second island
            int row = i/n, col = i%n;
            if(grid[row][col]) {
                dfs(row, col, n, grid);
                break;
            }
        }

        int answer = n*n;
        for(int i = 0; i < n*n; i++) { // connect second island from first island
            int row = i/n, col = i%n;
            if(grid[row][col] == 1) {
                vector<pi> water; // adjacent water coordination
                for(int j = 0; j < 4; j++) {
                    int new_row = row + dr[j];
                    int new_col = col + dc[j];
                    if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < n && !grid[new_row][new_col]) {
                        water.push_back({new_row, new_col});
                    }
                }
                for(int j = 0; j < water.size(); j++) {
                    int step = bfs(water[j].first, water[j].second, n, grid);
                    if(step == -1) { // cannot find second island
                        continue;
                    }
                    answer = min(answer, step);
                }
            }
        }
        return answer;
    }
};