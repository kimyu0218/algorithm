#include <iostream>
#include <queue>

using namespace std;

const int SIZE = 100, MAX = 10000;
int x_direction[4] = {0, -1, 0, 1}, y_direction[4] = {-1, 0, 1, 0}; // 상, 좌, 하, 우
bool apple[SIZE+1][SIZE+1] = { false, }, body[SIZE+1][SIZE+1] = { false, };
char change[MAX+1] = { '\0', }; // 방향 전환 정보
queue<pair<int, int>> snake; // (front : 꼬리, back : 머리)

void move_head(int idx) { // 머리 다음칸에 위치시키기
    pair<int, int> head = snake.back(); // 현재 뱀 머리 위치
    int row = head.first + y_direction[idx];
    int col = head.second + x_direction[idx];
    snake.push({row, col}); // 새로운 머리
}

void delete_tail() { // 꼬리 자르기
    pair<int, int> tail = snake.front(); snake.pop();
    body[tail.first][tail.second] = false;
}

int dummy_game(int n) {
    int sec = 0, idx = 3; // (게임 시작시 방향 오른쪽)
    snake.push({1, 1}); body[1][1] = true; // 게임 시작시 뱀 위치

    while(true) {
        sec++;
        move_head(idx); // 머리 다음칸으로 이동
        pair<int, int> head = snake.back(); // 새로운 머리 위치

        if((head.first > n || head.first < 1) || (head.second > n || head.second < 1)) break; // 벽에 부딪힌 경우 종료
        if(body[head.first][head.second]) break; // 자신의 몸과 부딪힌 경우 종료

        body[head.first][head.second] = true; // 새로운 머리 위치 세팅

        if(!apple[head.first][head.second]) delete_tail(); // 1. 이동한 칸에 사과가 없는 경우 꼬리 자르기
        else apple[head.first][head.second] = false; // 2. 이동한 칸에 사과가 있는 경우 사과 먹기

        if(change[sec] == 'D') idx = (idx-1 < 0 ? 3 : idx-1) % 4; // 오른쪽으로 회전
        else if(change[sec] == 'L') idx = (idx+1) % 4; // 왼쪽으로 회전
    }
    return sec;
}

int main() {
    int n, k, row, col, l, x;
    char c;
    cin >> n >> k; // 보드 크기, 사과 개수

    while(k--) { // 사과 위치 입력
        cin >> row >> col;
        apple[row][col] = true;
    }

    cin >> l; // 방향 전환 횟수
    while(l--) { // 방향 변환 정보 입력
        cin >> x >> c;
        change[x] = c;
    }

    cout << dummy_game(n);
    return 0;
}