#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX = 10, SIZE = 20;
struct info {
    int num; // 블록에 적힌 값
    bool conflict; // 블록 충돌 여부
};
int answer = 0;

void initialize(int n, info board[][SIZE]) { // conflict 값 false로 초기화
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j].conflict = false;
        }
    }
}

void copy(int n, info board[][SIZE], info new_board[][SIZE]) { // new_board에 board 값 복사하기
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            new_board[i][j] = board[i][j];
        }
    }
}

bool moveUp(int n, info board[][SIZE], info new_board[][SIZE]) { // 위쪽으로 기울이기
    bool flag = false;
    copy(n, board, new_board);
    for(int j = 0; j < n; j++) {
        for(int i = 1; i < n; i++) {
            if(!board[i][j].num) {
                continue;
            }
            int pos = 0; // 새롭게 이동할 위치
            for(int k = i-1; k >= 0; k--) {
                if(new_board[k][j].num) { // 빈 칸 아닌 곳 발견
                    pos = k+1;
                    break;
                }
            }
            if(pos != i) { // 1. 이동할 수 있는 경우
                flag = true;
                if(pos && new_board[pos-1][j].num == new_board[i][j].num && !new_board[pos-1][j].conflict) { // 1-1. 블록 충돌
                    new_board[pos-1][j] = {new_board[i][j].num * 2, true};
                }
                else { // 1-2. 블록 이동
                    new_board[pos][j] = new_board[i][j];
                }
                new_board[i][j] = {0, false};
            }
            else if(pos && new_board[pos-1][j].num == new_board[i][j].num && !new_board[pos-1][j].conflict) { // 2. 이동할 수 없지만 블록 충돌 가능
                flag = true;
                new_board[pos-1][j] = {new_board[i][j].num * 2, true};
                new_board[i][j] = {0, false};
            }
        }
    }
    return flag;
}

bool moveDown(int n, info board[][SIZE], info new_board[][SIZE]) { // 아래쪽으로 기울이기
    bool flag = false;
    copy(n, board, new_board);
    for(int j = 0; j < n; j++) {
        for(int i = n-2; i >= 0; i--) {
            if(!board[i][j].num) {
                continue;
            }
            int pos = n-1; // 새롭게 이동할 위치
            for(int k = i+1; k < n; k++) {
                if(new_board[k][j].num) { // 빈 칸 아닌 곳 발견
                    pos = k-1;
                    break;
                }
            }
            if(pos != i) { // 1. 이동할 수 있는 경우
                flag = true;
                if(pos < n-1 && new_board[pos+1][j].num == new_board[i][j].num && !new_board[pos+1][j].conflict) { // 1-1. 블록 충돌
                    new_board[pos+1][j] = {new_board[i][j].num * 2, true};
                }
                else { // 1-2. 블록 이동
                    new_board[pos][j] = new_board[i][j];
                }
                new_board[i][j] = {0, false};
            }
            else if(pos < n-1 && new_board[pos+1][j].num == new_board[i][j].num && !new_board[pos+1][j].conflict) { // 2. 이동할 수 없지만 블록 충돌 가능
                flag = true;
                new_board[pos+1][j] = {new_board[i][j].num * 2, true};
                new_board[i][j] = {0, false};
            }
        }
    }
    return flag;
}

bool moveLeft(int n, info board[][SIZE], info new_board[][SIZE]) { // 왼쪽으로 기울이기
    bool flag = false;
    copy(n, board, new_board);
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(!board[i][j].num) {
                continue;
            }
            int pos = 0; // 새롭게 이동할 위치
            for(int k = j-1; k >= 0; k--) {
                if(new_board[i][k].num) { // 빈 칸 아닌 곳 발견
                    pos = k+1;
                    break;
                }
            }
            if(pos != j) { // 1. 이동할 수 있는 경우
                flag = true;
                if(pos && new_board[i][pos-1].num == new_board[i][j].num && !new_board[i][pos-1].conflict) { // 1-1. 블록 충돌
                    new_board[i][pos-1] = {new_board[i][j].num * 2, true};
                }
                else { // 1-2. 블록 이동
                    new_board[i][pos] = new_board[i][j];
                }
                new_board[i][j] = {0, false};
            }
            else if (pos && new_board[i][pos-1].num == new_board[i][j].num && !new_board[i][pos-1].conflict) { // 2. 이동할 수는 없지만 블록 충돌 가능
                flag = true;
                new_board[i][pos-1] = {new_board[i][j].num * 2, true};
                new_board[i][j] = {0, false};
            }
        }
    }
    return flag;
}

bool moveRight(int n, info board[][SIZE], info new_board[][SIZE]) { // 오른쪽으로 기울이기
    bool flag = false;
    copy(n, board, new_board);
    for(int i = 0; i < n; i++) {
        for(int j = n-2; j >= 0; j--) {
            if(!board[i][j].num) {
                continue;
            }
            int pos = n-1; // 새롭게 이동할 위치
            for(int k = j+1; k < n; k++) {
                if(new_board[i][k].num) { // 빈 칸 아닌 곳 발견
                    pos = k-1;
                    break;
                }
            }
            if(pos != j) { // 1. 이동할 수 있는 경우
                flag = true;
                if(pos < n-1 && new_board[i][pos+1].num == new_board[i][j].num && !new_board[i][pos+1].conflict) { // 1-1. 블록 충돌
                    new_board[i][pos+1] = {new_board[i][j].num * 2, true};
                }
                else { // 1-2. 블록 이동
                    new_board[i][pos] = new_board[i][j];
                }
                new_board[i][j] = {0, false};
            }
            else if(pos < n-1 && new_board[i][pos+1].num == new_board[i][j].num && !new_board[i][pos+1].conflict) { // 2. 이동할 수 없지만 블록 충돌 가능
                flag = true;
                new_board[i][pos+1] = {new_board[i][j].num * 2, true};
                new_board[i][j] = {0, false};
            }
        }
    }
    return flag;
}

int biggestBlock(int n, info board[][SIZE]) { // 가장 큰 블록값 구하기
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, board[i][j].num);
        }
    }
    return ans;
}

void backtracking(int cnt, int n, info board[][SIZE]) {
    int tmp = biggestBlock(n, board);
    answer = max(answer, tmp);
    if(tmp * pow(2, MAX-1-cnt) < answer || cnt == MAX) { // 기저조건
        return;
    }

    info new_board[SIZE][SIZE];
    initialize(n, board); // conflict 값 초기화
    // 1. 왼쪽으로 기울이기
    bool left = moveLeft(n, board, new_board);
    if(left) {
        backtracking(cnt+1, n, new_board);
    }
    // 2. 오른쪽으로 기울이기
    bool right = moveRight(n, board, new_board);
    if(right) {
        backtracking(cnt+1, n, new_board);
    }
    // 3. 위쪽으로 기울이기
    bool up = moveUp(n, board, new_board);
    if(up) {
        backtracking(cnt+1, n, new_board);
    }
    // 4. 아래쪽으로 기울이기
    bool down = moveDown(n, board, new_board);
    if(down) {
        backtracking(cnt+1, n, new_board);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    info board[SIZE][SIZE];

    cin >> n;
    for(int i = 0; i < n; i++) { // 게임판 초기 상태 입력
        for(int j = 0; j < n; j++) {
            cin >> board[i][j].num;
        }
    }

    backtracking(0, n, board);
    cout << answer;
    return 0;
}