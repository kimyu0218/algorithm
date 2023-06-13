#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(int m, vector<vector<int>> &key) { // 열쇠 시계 방향으로 90도 회전하기
    vector<vector<int>> rotated_key (m, vector<int> (m, 0));
    for(int i = 0; i < m; i++) { // i : 행
        for(int j = 0; j < m; j++) { // j : 열
            rotated_key[j][m-1-i] = key[i][j];
        }
    }
    return rotated_key;
}

bool match(int cnt, int row, int col, int m, int n, vector<vector<int>> &key, vector<vector<int>> &lock) { // row : 열쇠가 상하로 이동한 거리, col : 열쇠가 좌우로 이동한 거리
    int sr = (row < 0) ? 0 : row; // 열쇠가 위로 이동한 경우 자물쇠의 0번째 행부터 검사 / 열쇠가 아래로 이동한 경우 자물쇠의 row번째 행부터 검사
    int er = (row > 0) ? n : m+row; // 열쇠가 아래로 이동한 경우 자물쇠의 n-1번째 행까지 검사 / 열쇠가 위로 이동한 경우 자물쇠의 m+row-1번째 행까지 검사
    int sc = (col < 0) ? 0 : col; // 열쇠가 왼쪽으로 이동한 경우 자물쇠의 0번째 열부터 검사 / 열쇠가 오른쪽으로 이동한 경우 자물쇠의 col번째 열부터 검사
    int ec = (col > 0) ? n : m+col; // 열쇠가 오른쪽으로 이동한 경우 자물쇠의 n-1번째 열까지 검사 / 열쇠가 왼쪽으로 이동한 경우 자물쇠의 m+col번째 열까지 검사

    for(int i = sr; i < er; i++) {
        for(int j = sc; j < ec; j++) {
            if(i-row < 0 || j - col < 0 || i-row >= m || j-col >= m) {
                continue;
            }
            if(key[i-row][j-col] && lock[i][j]) { // 1. 열쇠와 자물쇠 둘 다 돌기인 경우 실패
                return false;
            }
            if(key[i-row][j-col] && !lock[i][j]) { // 2. 열쇠의 돌기와 자물쇠의 홈 일치
                cnt--;
            }
        }
    }
    return cnt == 0; // 자물쇠의 홈을 다 채웠는가
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size(), n = lock.size();
    int cnt = 0; // 자물쇠의 홈 개수

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!lock[i][j]) {
                cnt++;
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        // 1. 열쇠의 이동
        for(int row = -(m-1); row <= n-1; row++) {
            for(int col = -(m-1); col <= n-1; col++) {
                bool result = match(cnt, row, col, m, n, key, lock);
                if(result) { // 자물쇠 열기 성공 -> 바로 답 리턴
                    return true;
                }
            }
        }
        if(i == 3) {
            break;
        }
        // 2. 열쇠의 회전
        key = rotate(m, key);
    }
    return false;
}