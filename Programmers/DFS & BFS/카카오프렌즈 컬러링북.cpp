#include <vector>

using namespace std;

int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
vector<vector<bool>> visited;

int dfs(int r, int c, int m, int n, vector<vector<int>> &picture) {
    int area = 1, color = picture[r][c];
    visited[r][c] = true; // 방문 체크

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        // 같은 색상 발견
        if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && color == picture[nr][nc]) {
            area += dfs(nr, nc, m, n, picture);
        }
    }
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    visited.assign(m, vector<bool> (n, false));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(picture[i][j] && !visited[i][j]) { // 아직 방문하지 않은, 색칠해야 하는 영역 발견
                number_of_area++;
                int area = dfs(i, j, m, n, picture);
                max_size_of_one_area = max(max_size_of_one_area, area);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}