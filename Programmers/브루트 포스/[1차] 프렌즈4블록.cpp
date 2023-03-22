#include <string>
#include <vector>

using namespace std;

const char BLANK = '0';
typedef pair<int, int> pi;

/*
 * 1번 2번
 * 3번 4번
*/
bool canPop(int r, int c, int m, int n, vector<string> &board) { // 2x2 pop 가능한가 (r,c : 1번의 좌표)
    int nr = r + 1, nc = c + 1;
    if(nr >= m || nc >= n) { // 좌표 벗어남
        return false;
    }

    char shape = board[r][c];
    if(board[r][nc] != shape || board[nr][c] != shape || board[nr][nc] != shape) { // 2번, 3번, 4번 모양 확인
        return false;
    }
    return true;
}

void pop(vector<string> &board, vector<pi> pop_list) { // pop 처리 (-> 빈칸으로)
    for(int i = 0; i < pop_list.size(); i++) {
        int r = pop_list[i].first, c = pop_list[i].second;
        int nr = r + 1, nc = c + 1;
        board[r][c] = board[r][nc] = board[nr][c] = board[nr][nc] = BLANK;
    }
}

void fallDown(int m, int n, vector<string> &board) {
    for(int j = 0; j < n; j++) { // j : 열
        for(int i = m-1; i >= 0; i--) {
            if(board[i][j] == BLANK) { // 빈 칸 pass
                continue;
            }

            // (i, j) -> (pos, j) 떨어뜨리기
            int pos = m-1;
            for(int k = i+1; k < m; k++) {
                if(board[k][j] != BLANK) { // 더 이상 빈 칸 없음
                    pos = k-1;
                    break;
                }
            }
            if(pos != i) { // 블록 떨어뜨릴 수 있음
                board[pos][j] = board[i][j];
                board[i][j] = BLANK;
            }
        }
    }
}

vector<pi> bruteforce(int m, int n, vector<string> &board) { // pop 할 수 있는 위치 반환
    vector<pi> list;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] != BLANK && canPop(i, j, m, n, board)) { // 2x2 pop 가능한 좌표 발견
                list.push_back({i, j});
            }
        }
    }
    return list;
}


int cntPop(int m, int n, vector<string> &board) { // pop된 블록의 개수 세기 (= 빈 칸의 개수가 곧 pop된 블록 수)
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == BLANK) {
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int m, int n, vector<string> board) {
    while(true) {
        vector<pi> pop_list = bruteforce(m, n, board);
        if(pop_list.empty()) { // 더 이상 pop할 블록 없음
            break;
        }
        pop(board, pop_list);
        fallDown(m, n, board);
    }
    return cntPop(m, n, board);
}