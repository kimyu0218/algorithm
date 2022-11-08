#include <iostream>
#include <queue>

using namespace std;

const int SIZE = 100;
typedef pair<int, int> pi;
typedef struct dir_info{ // 방향 전환 정보
    int x;
    char c;
}di;
int n, d = 0; // 보드 크기, 뱀의 이동 방향
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // (오른쪽으로 시계방향 회전)
int board[SIZE+1][SIZE+1]; // (0: 없음, 1: 뱀, 2: 사과)
queue<pi> snake; // (front: 꼬리 위치, back: 머리 위치)
bool game_over = false; // 게임 종료 여부

void move() { // 뱀의 이동
    // 다음칸
    int next_row = snake.back().first + dy[d];
    int next_col = snake.back().second + dx[d];

    // 종료 조건 : 벽에 부딪힌 경우, 자기자신의 몸과 부딪힌 경우
    if(next_row <= 0 || next_row > n || next_col <= 0 || next_col > n || board[next_row][next_col] == 1) {
        game_over = true;
        return;
    }

    if(board[next_row][next_col] == 0) { // 사과 없으면 꼬리 이동해서 몸 길이 유지
        pi tail = snake.front(); snake.pop();
        board[tail.first][tail.second] = 0; // 꼬리 다음칸으로 이동 (현재 꼬리 빈칸으로)
    }

    board[next_row][next_col] = 1; // 머리 이동
    snake.push({next_row, next_col});
}

int game(queue<di> q) { // (q : 방향 전환 정보)
    snake.push({1, 1}); // 뱀 시작 위치
    board[1][1] = 1;

    int sec = 0; // 게임 진행 시간
    while(!game_over) {
        if(!q.empty() && sec == q.front().x) { // 방향 전환이 일어나는 경우
            char dir = q.front().c; q.pop();
            if(dir == 'L') { // 왼쪽으로 회전
                d = (d+3) % 4;
            }
            else if(dir == 'D') { // 오른쪽으로 회전
                d = (d+1) % 4;
            }
        }
        move(); sec++;
    }
    return sec;
}

int main() {
    int k, l;
    cin >> n >> k;

    int row, col;
    while(k--) { // 사과 위치 입력
        cin >> row >> col;
        board[row][col] = 2;
    }

    cin >> l;
    queue<di> q;
    int x; char c;
    while(l--) { // 방향 변환 정보 입력
        cin >> x >> c;
        q.push({x, c});
    }

    cout << game(q);
    return 0;
}