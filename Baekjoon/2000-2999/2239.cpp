#include <iostream>

using namespace std;

const int SIZE = 9;

bool check_row[SIZE][SIZE+1], check_col[SIZE][SIZE+1], check_square[SIZE][SIZE+1];
int sudoku[SIZE][SIZE]; // 스도쿠 판

int squareNum(int row, int col) { // 사각형 번호 계산
    return (row/3) * 3 + (col/3);
}

void backtracking(int idx) {
    if(idx == SIZE*SIZE) { // 기저 조건 : 스도쿠 완성
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                cout << sudoku[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }

    int row = idx / SIZE;
    int col = idx % SIZE;
    if(sudoku[row][col]) { // 이미 칸이 채워져 있는 경우
        backtracking(idx+1);
    }
    int square = squareNum(row, col);

    for(int i = 1; i <= SIZE; i++) { // i 수를 넣어보자
        if(check_row[row][i] || check_col[col][i] || check_square[square][i]) { // i 수 넣을 수 없음
            continue;
        }
        // 방문 체크
        sudoku[row][col] = i;
        check_row[row][i] = check_col[col][i] = check_square[square][i] = true;
        backtracking(idx+1);
        // 방문 체크 취소
        check_row[row][i] = check_col[col][i] = check_square[square][i] = false;
        sudoku[row][col] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;
    for(int i = 0; i < SIZE; i++) {
        cin >> input;
        for(int j = 0; j < SIZE; j++) {
            if(!input[j]) { // 빈 칸 pass
                continue;
            }
            int num = input[j] - '0';
            int square = squareNum(i, j);
            sudoku[i][j] = num;
            check_row[i][num] = check_col[j][num] = check_square[square][num] = true;
        }
    }

    backtracking(0);
    return 0;
}