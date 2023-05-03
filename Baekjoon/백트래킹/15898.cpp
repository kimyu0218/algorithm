#include <iostream>
#include <vector>

using namespace std;

const int K_SIZE = 5, M_SIZE = 4, DIR = 4, CNT = 3, LIMIT = 10; // 가마 크기, 재료 크기, 폭탄을 만들기 위해 필요한 재료 개수
struct info {
    int effect; // 효능
    char color; // 색상
};
int n, answer = 0;
bool used[LIMIT] = {false, }; // i번째 재료 이용 여부
vector<vector<info>> kiln; // 가마
info m[LIMIT][DIR][M_SIZE][M_SIZE]; // 재료 (info[i][d] : i번째 재료를 90*d도 회전한 값)

void rotate90(int idx) { // 재료 회전
    for(int k = 0; k < 3; k++) { // 90, 180, 270도 회전
        for(int i = 0; i < M_SIZE; i++) {
            for(int j = 0; j < M_SIZE; j++) {
                m[idx][k+1][j][M_SIZE-1-i] = m[idx][k][i][j];
            }
        }
    }
}

int quality(vector<vector<info>> &k) { // 폭탄 품질 계산하기
    int r = 0, b = 0, g = 0, y = 0;
    for(int i = 0; i < K_SIZE; i++) {
        for(int j = 0; j < K_SIZE; j++) {
            switch(k[i][j].color) {
                case 'R':
                    r += k[i][j].effect;
                    break;
                case 'B':
                    b += k[i][j].effect;
                    break;
                case 'G':
                    g += k[i][j].effect;
                    break;
                case 'Y':
                    y += k[i][j].effect;
                    break;
            }
        }
    }
    return 7*r + 5*b + 3*g + 2*y;
}

vector<vector<info>> putMaterial(int row, int col, int idx, int dir, vector<vector<info>> k) { // idx번째 재료의 90도로 dir번 회전한 형태 넣기
    for(int i = 0; i < M_SIZE; i++) {
        for(int j = 0; j < M_SIZE; j++) {
            int nr = i + row, nc = j + col;
            k[nr][nc].effect += m[idx][dir][i][j].effect;
            if(k[nr][nc].effect < 0) { // 음수 -> 0
                k[nr][nc].effect = 0;
            }
            else if(k[nr][nc].effect > 9) { // 10이상 -> 9
                k[nr][nc].effect = 9;
            }
            if(m[idx][dir][i][j].color != 'W') { // 색상 변경
                k[nr][nc].color = m[idx][dir][i][j].color;
            }
        }
    }
    return k;
}

void backtracking(int cnt, vector<vector<info>> k) {
    if(cnt == CNT) { // 재료 3개 사용 완료
        answer = max(answer, quality(k));
        return;
    }
    for(int i = 0; i < n; i++) {
        if(used[i]) { // 이미 사용한 재료 pass
            continue;
        }
        used[i] = true; // 사용 체크
        for(int r = 0; r <= 1; r++) { // 재료 놓을 수 있는 위치 (r, c)
            for(int c = 0; c <= 1; c++) {
                vector<vector<info>> k_rev;
                for(int j = 0; j < DIR; j++) { // 회전한 재료 (r, c) 위치에 놓기
                    k_rev = putMaterial(r, c, i, j, k);
                    backtracking(cnt+1, k_rev);
                }
            }
        }
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    kiln.assign(K_SIZE, vector<info> (K_SIZE, {0, 'W'})); // 가마 초기 상태 세팅
    for(int i = 0; i < n; i++) { // 재료 인덱스
        for(int j = 0; j < M_SIZE; j++) { // 효능 입력
            for(int k = 0; k < M_SIZE; k++) {
                cin >> m[i][0][j][k].effect;
            }
        }
        for(int j = 0; j < M_SIZE; j++) { // 색상 입력
            for(int k = 0; k < M_SIZE; k++) {
                cin >> m[i][0][j][k].color;
            }
        }
        rotate90(i); // i번재 재료 90, 180, 270도 회전
    }

    backtracking(0, kiln);
    cout << answer;
    return 0;
}