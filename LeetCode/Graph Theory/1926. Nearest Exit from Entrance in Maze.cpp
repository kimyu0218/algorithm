class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
        queue<vector<int>> q;
        vector<vector<int>> step (n, vector<int> (m, -1));

        q.push({entrance[0], entrance[1]});
        step[entrance[0]][entrance[1]] = 0;

        while(!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            q.pop();

            for(int i = 0; i < 4; i++) {
                int new_row = row + dr[i];
                int new_col = col + dc[i];

                if(new_row < 0 || new_col < 0 || new_row >= n || new_col >= m) {
                    if(row == entrance[0] && col == entrance[1]) {
                        continue;
                    }
                    return step[row][col];
                }
                if(maze[new_row][new_col] == '.' && step[new_row][new_col] == -1) {
                    step[new_row][new_col] = step[row][col] + 1;
                    q.push({new_row, new_col});
                }
            }
        }
        return -1;
    }
};