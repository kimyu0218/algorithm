#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

/*
 * 3 x 3 사각 격자
 * 가운데 칸 막혀있음, 대신 숫자 표시
 * 숫자는 4개까지 표시
 * 숫자 == 초콜릿이 들어있는 연결된 칸의 개수
 * 오름차순으로 표시
*/
int dfs(int row, int col) {
    int cnt = 1;
    board[row][col] = 'X';

    for(int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if(nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE && board[nr][nc] == 'O') {
            cnt += dfs(nr, nc);
        }
    }
    return cnt;
}

bool solution(int n, vector<int> &a) {
    vector<int> nums;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == 'O') {
                nums.push_back(dfs(i, j));
            }
        }
    }

    if(n != nums.size()) {
        return false;
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++) {
        if(a[i] != nums[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t, n;
    vector<int> a;

    cin >> t;
    while(t--) {
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                cin >> board[i][j];
            }
        }
        cin >> n;
        a.assign(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solution(n, a) << '\n';
    }
    return 0;
}