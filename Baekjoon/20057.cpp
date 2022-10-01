#include <iostream>

using namespace std;

const int SIZE = 499;
int n, out = 0; // (out : 격자 밖으로 나간 모래의 양)
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // 토네이도 회전방향
int sand[SIZE][SIZE];

void percentA(int row, int col, int dir, int amount) { // 토네이도 방향으로 한 칸 전진
    int nr = row+dy[dir], nc = col+dx[dir];
    if(nr < 0 || nr >= n || nc < 0 || nc >= n) out += amount; // 격자 밖으로 나간 경우
    else sand[nr][nc] += amount;
}

void percent5(int row, int col, int dir, int amount) { // 토네이도 방향으로 두 칸 전진
    int nr = row+dy[dir]*2, nc = col+dx[dir]*2;
    if(nr < 0 || nr >= n || nc < 0 || nc >= n) out += amount; // 격자 밖으로 나간 경우
    else sand[nr][nc] += amount;
}

void percent10(int row, int col, int dir, int amount) { // 토네이도 방향으로 한 칸 전진 후 각각 반시계, 시계 방향 회전
    int nr1 = row+dy[dir]+dy[(dir+3)%4], nc1 = col+dx[dir]+dx[(dir+3)%4];
    if(nr1 < 0 || nr1 >= n || nc1 < 0 || nc1 >= n) out += amount; // 격자 밖으로 나간 경우
    else sand[nr1][nc1] += amount;

    int nr2 = row+dy[dir]+dy[(dir+1)%4], nc2 = col+dx[dir]+dx[(dir+1)%4];
    if(nr2 < 0 || nr2 >= n || nc2 < 0 || nc2 >= n) out += amount; // 격자 밖으로 나간 경우
    else sand[nr2][nc2] += amount;
}

void percent7(int row, int col, int dir, int amount) { // 토네이도 방향에서 각각 반시계, 시계 방향 회전
    int nr1 = row+dy[(dir+3)%4], nc1 = col+dx[(dir+3)%4];
    if(nr1 < 0 || nr1 >= n || nc1 < 0 || nc1 >= n) out += amount; // 격자 밖으로 나간 경우
    else sand[nr1][nc1] += amount;

    int nr2 = row+dy[(dir+1)%4], nc2 = col+dx[(dir+1)%4];
    if(nr2 < 0 || nr2 >= n || nc2 < 0 || nc2 >= n) out += amount; // 격자 밖으로 나간 경우
    else sand[nr2][nc2] += amount;
}

void percent2(int row, int col, int dir, int amount) { // 토네이도 방향에서 각각 반시계, 시계 방향 회전 후 두 칸 전진
    int nr1 = row+2*dy[(dir+3)%4], nc1 = col+2*dx[(dir+3)%4];
    if(nr1 < 0 || nr1 >= n || nc1 < 0 || nc1 >= n) out += amount; // 격자 밖으로 나간 경우
    else sand[nr1][nc1] += amount;

    int nr2 = row+2*dy[(dir+1)%4], nc2 = col+2*dx[(dir+1)%4];
    if(nr2 < 0 || nr2 >= n || nc2 < 0 || nc2 >= n) out += amount; // 격자 밖으로 나간 경우
    else sand[nr2][nc2] += amount;
}

void percent1(int row, int col, int dir, int amount) { // 토네이도 방향에서 후진 후 각각 반시계, 시계 방향 회전
    int back_dir = (dir+2) % 4;
    int nr1 = row+dy[back_dir]+dy[(dir+3)%4], nc1 = col+dx[back_dir]+dx[(dir+3)%4];
    if(nr1 < 0 || nr1 >= n || nc1 < 0 || nc1 >= n) out += amount; // 격자 밖으로 나간 경우
    else sand[nr1][nc1] += amount;

    int nr2 = row+dy[back_dir]+dy[(dir+1)%4], nc2 = col+dx[back_dir]+dx[(dir+1)%4];
    if(nr2 < 0 || nr2 >= n || nc2 < 0 || nc2 >= n) out += amount; // 격자 밖으로 나간 경우
    else sand[nr2][nc2] += amount;
}

void tornado(int row, int col, int dir, int size) {
    for(int i = 0; i < size; i++) { // 토네이도 크기
        if(row == 0 && col == 0) return; // 기저 조건 : 토네이도 소멸
        row += dy[dir]; col += dx[dir];

        int amount = sand[row][col]; // y위치(=토네이도 위치)의 모래 양
        sand[row][col] = 0;

        // 이동한 모래양
        int spread = (int) (amount * 0.05) + 2 * ((int) (amount * 0.1)) + 2 * ((int) (amount * 0.07))
                + 2 * ((int) (amount * 0.02)) + 2 * ((int) (amount * 0.01));
        percent5(row, col, dir, amount*0.05);
        percent10(row, col, dir, amount*0.1);
        percent7(row, col, dir, amount*0.07);
        percent2(row, col, dir, amount*0.02);
        percent1(row, col, dir, amount*0.01);
        percentA(row, col, dir, amount - spread);
    }

    int next_dir = (dir+1) % 4;
    if(next_dir % 2 == 0) size++;
    tornado(row, col, next_dir, size);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) { // 모래 입력
        for(int j = 0; j < n; j++) {
            cin >> sand[i][j];
        }
    }

    tornado(n/2, n/2, 0, 1); // 격자 가운데 칸부터 토네이도 시작
    cout << out;
    return 0;
}