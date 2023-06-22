#include <iostream>
#include <vector>

using namespace std;
const int MAX = 5;
struct info {
    int num;
    bool conflict;
};
int answer = 0;

void initialize(int n, vector<vector<info>> &board) { // conflict 값 false로 초기화
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j].conflict = false;
        }
    }
}

vector<vector<info>> moveUp(int n, vector<vector<info>> &board) { // 위쪽으로 기울이기
    vector<vector<info>> nb = board;
    for(int j = 0; j < n; j++) {
        for(int i = 1; i < n; i++) {
            if(!board[i][j].num) {
                continue;
            }
            int pos = 0; // 새롭게 이동할 위치
            for(int k = i-1; k >= 0; k--) {
                if(nb[k][j].num) { // 빈 칸 아닌 곳 발견
                    pos = k+1;
                    break;
                }
            }
            if(pos != i) { // 1. 이동할 수 있는 경우
                if(pos && nb[pos-1][j].num == nb[i][j].num && !nb[pos-1][j].conflict) { // 1-1. 블록 충돌
                    nb[pos-1][j] = {nb[i][j].num * 2, true};
                }
                else { // 1-2. 블록 이동
                    nb[pos][j] = nb[i][j];
                }
                nb[i][j] = {0, false};
            }
            else if(pos && nb[pos-1][j].num == nb[i][j].num && !nb[pos-1][j].conflict) { // 2. 이동할 수 없지만 블록 충돌 가능
                nb[pos-1][j] = {nb[i][j].num * 2, true};
                nb[i][j] = {0, false};
            }
        }
    }
    return nb;
}

vector<vector<info>> moveDown(int n, vector<vector<info>> &board) { // 아래쪽으로 기울이기
    vector<vector<info>> nb = board;
    for(int j = 0; j < n; j++) {
        for(int i = n-2; i >= 0; i--) {
            if(!board[i][j].num) {
                continue;
            }
            int pos = n-1; // 새롭게 이동할 위치
            for(int k = i+1; k < n; k++) {
                if(nb[k][j].num) { // 빈 칸 아닌 곳 발견
                    pos = k-1;
                    break;
                }
            }
            if(pos != i) { // 1. 이동할 수 있는 경우
                if(pos < n-1 && nb[pos+1][j].num == nb[i][j].num && !nb[pos+1][j].conflict) { // 1-1. 블록 충돌
                    nb[pos+1][j] = {nb[i][j].num * 2, true};
                }
                else { // 1-2. 블록 이동
                    nb[pos][j] = nb[i][j];
                }
                nb[i][j] = {0, false};
            }
            else if(pos < n-1 && nb[pos+1][j].num == nb[i][j].num && !nb[pos+1][j].conflict) { // 2. 이동할 수 없지만 블록 충돌 가능
                nb[pos+1][j] = {nb[i][j].num * 2, true};
                nb[i][j] = {0, false};
            }
        }
    }
    return nb;
}

vector<vector<info>> moveLeft(int n, vector<vector<info>> &board) { // 왼쪽으로 기울이기
    vector<vector<info>> nb = board;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(!board[i][j].num) {
                continue;
            }
            int pos = 0; // 새롭게 이동할 위치
            for(int k = j-1; k >= 0; k--) {
                if(nb[i][k].num) { // 빈 칸 아닌 곳 발견
                    pos = k+1;
                    break;
                }
            }
            if(pos != j) { // 1. 이동할 수 있는 경우
                if(pos && nb[i][pos-1].num == nb[i][j].num && !nb[i][pos-1].conflict) { // 1-1. 블록 충돌
                    nb[i][pos-1] = {nb[i][j].num * 2, true};
                }
                else { // 1-2. 블록 이동
                    nb[i][pos] = nb[i][j];
                }
                nb[i][j] = {0, false};
            }
            else if (pos && nb[i][pos-1].num == nb[i][j].num && !nb[i][pos-1].conflict) { // 2. 이동할 수는 없지만 블록 충돌 가능
                nb[i][pos-1] = {nb[i][j].num * 2, true};
                nb[i][j] = {0, false};
            }
        }
    }
    return nb;
}

vector<vector<info>> moveRight(int n, vector<vector<info>> &board) { // 오른쪽으로 기울이기
    vector<vector<info>> nb = board;
    for(int i = 0; i < n; i++) {
        for(int j = n-2; j >= 0; j--) {
            if(!board[i][j].num) {
                continue;
            }
            int pos = n-1; // 새롭게 이동할 위치
            for(int k = j+1; k < n; k++) {
                if(nb[i][k].num) { // 빈 칸 아닌 곳 발견
                    pos = k-1;
                    break;
                }
            }
            if(pos != j) { // 1. 이동할 수 있는 경우
                if(pos < n-1 && nb[i][pos+1].num == nb[i][j].num && !nb[i][pos+1].conflict) { // 1-1. 블록 충돌
                    nb[i][pos+1] = {nb[i][j].num * 2, true};
                }
                else { // 1-2. 블록 이동
                    nb[i][pos] = nb[i][j];
                }
                nb[i][j] = {0, false};
            }
            else if(pos < n-1 && nb[i][pos+1].num == nb[i][j].num && !nb[i][pos+1].conflict) { // 2. 이동할 수 없지만 블록 충돌 가능
                nb[i][pos+1] = {nb[i][j].num * 2, true};
                nb[i][j] = {0, false};
            }
        }
    }
    return nb;
}

int biggestBlock(int n, vector<vector<info>> &board) { // 가장 큰 블록값 구하기
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, board[i][j].num);
        }
    }
    return ans;
}

void backtracking(int cnt, int n, vector<vector<info>> board) {
    if(cnt == MAX) { // 기저조건 : 5번 이동완료
        int tmp = biggestBlock(n, board);
        answer = max(answer, tmp);
        return;
    }

    initialize(n, board); // conflict 값 초기화
    // 1. 왼쪽으로 기울이기
    vector<vector<info>> left = moveLeft(n, board);
    backtracking(cnt+1, n, left);
    // 2. 오른쪽으로 기울이기
    vector<vector<info>> right = moveRight(n, board);
    backtracking(cnt+1, n, right);
    // 3. 위쪽으로 기울이기
    vector<vector<info>> up = moveUp(n, board);
    backtracking(cnt+1, n, up);
    // 4. 아래쪽으로 기울이기
    vector<vector<info>> down = moveDown(n, board);
    backtracking(cnt+1, n, down);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    vector<vector<info>> board;
    cin >> n;

    board.assign(n, vector<info> (n, {0, false}));
    for(int i = 0; i < n; i++) { // 게임판 초기 상태 입력
        for(int j = 0; j < n; j++) {
            cin >> board[i][j].num;
        }
    }

    backtracking(0, n, board);
    cout << answer;
    return 0;
}