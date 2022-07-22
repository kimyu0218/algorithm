#include <iostream>

using namespace std;

const int SIZE = 9;
bool complete = false;
int sudoku[SIZE][SIZE];

// 1. 세로줄 확인
bool check_col(int row, int col, int num) {
    for(int i = 0; i < SIZE; i++) {
        if(i == row) continue;
        if(sudoku[i][col] == num) return false; // 숫자 중복
    }
    return true;
}

// 2. 가로줄 확인
bool check_row(int row, int col, int num) {
    for(int i = 0; i < SIZE; i++) {
        if(i == col) continue;
        if(sudoku[row][i] == num) return false; // 숫자 중복
    }
    return true;
}

// 3. 3x3 정사각형 확인
bool check_square(int row, int col, int num) {
    int p1 = 3 * (row/3), p2 = 3 * (col/3);
    for(int i = p1; i < p1+3; i++) {
        for(int j = p2; j < p2+3; j++) {
            if(i == row && j == col) continue;
            if(sudoku[i][j] == num) return false;
        }
    }
    return true;
}

void backtracking(int idx) {
    if(idx == SIZE * SIZE) {
        complete = true; // (하나라도 찾으면 되기 때문에 곧바로 종료)
        return;
    }

    int row = idx / SIZE, col = idx % SIZE;
    if(sudoku[row][col]) return backtracking(idx+1); // 이미 채워진 값 pass

    for(int i = 1; i <= SIZE; i++) { // 비어있는 칸 1부터 9까지 넣어보기
        if(!check_row(row, col, i) || !check_col(row, col, i) || !check_square(row, col, i)) continue; // i가 올 수 없는 경우 pass
        sudoku[row][col] = i;
        backtracking(idx+1);
        if(complete) return;
        sudoku[row][col] = 0;
    }
}

int main() {
    for(int i = 0; i < SIZE; i++) { // 스도쿠 입력받기
        for(int j = 0; j < SIZE; j++)
            cin >> sudoku[i][j];
    }

    backtracking(0);
    for(int i = 0; i < SIZE; i++) { // 완성한 스도쿠 출력
        for(int j = 0; j < SIZE; j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}