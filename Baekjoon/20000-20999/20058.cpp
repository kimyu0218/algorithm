#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int, int> pi;
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

void rotate(int row, int col, int size, vector<vector<int>> &a) {
    vector<vector<int>> tmp (size, vector<int> (size, 0));
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            tmp[j][size-1-i] = a[row+i][col+j];
        }
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            a[row+i][col+j] = tmp[i][j];
        }
    }
}

void melt(int size, vector<vector<int>> &a) {
    vector<vector<int>> next = a;
    for(int r = 0; r < size; r++) {
        for(int c = 0; c < size; c++) {
            if(a[r][c] == 0) { // 얼음이 없는 칸 pass
                continue;
            }
            int cnt = 0; // 인접한 얼읔수
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr >= 0 && nr < size && nc >= 0 && nc < size && a[nr][nc]) {
                    cnt++;
                }
            }
            if(cnt < 3) { // 인접한 얼음이 3개 미만인 경우, 얼음양 줄음
                next[r][c]--;
            }
        }
    }
    a = next;
}

void firestorm(int size, int q, vector<int> &l, vector<vector<int>> &a) {
    for(int i = 0; i < q; i++) {
        // 1. 모든 부분 격자 시계 방향 90도로 회전
        int part_size = pow(2, l[i]);
        for(int r = 0; r < size; r += part_size) {
            for(int c = 0; c < size; c += part_size) {
                rotate(r, c, part_size, a);
            }
        }
        // 2. 얼음양 줄기
        melt(size, a);
    }
}

int dfs(int r, int c, int size, vector<vector<int>> &a, vector<vector<bool>> &visited) { // 덩어리 개수 세기
    int cnt = 1;
    visited[r][c] = true;

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr >= 0 && nr < size && nc >= 0 && nc < size && a[nr][nc] && !visited[nr][nc]) {
            cnt += dfs(nr, nc, size, a, visited);
        }
    }
    return cnt;
}

pi magicShark(int size, int q, vector<int> &l, vector<vector<int>> &a) {
    int sum = 0, cnt = 0;
    vector<vector<bool>> visited (size, vector<bool> (size, false));

    firestorm(size, q, l, a); // 파이어스톰 실행

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            sum += a[i][j];
            if(a[i][j] && !visited[i][j]) { // 아직 방문하지 않은 얼음인 경우
                int tmp = dfs(i, j, size, a, visited);
                cnt = max(cnt, tmp);
            }
        }
    }
    return {sum, cnt};
}

int main() {
    int n, q, size;
    vector<int> l;
    vector<vector<int>> a;
    
    cin >> n >> q;
    size = pow(2, n);
    l.assign(q, 0);
    a.assign(size, vector<int> (size, 0));

    for(int i = 0; i < size; i++) { // 얼음양 입력
        for(int j = 0; j < size; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < q; i++) { // 단계 입력
        cin >> l[i];
    }

    pi ans = magicShark(size, q, l, a);
    cout << ans.first << '\n' << ans.second;
    return 0;
}