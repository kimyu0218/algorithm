#include <iostream>

using namespace std;

const int SIZE = 9;
bool complete = false;
bool check1[SIZE][SIZE+1] = { false, }, check2[SIZE][SIZE+1] = { false, }, check3[SIZE][SIZE+1] = { false, }; // 각각 가로, 세로, 정사각형
int sudoku[SIZE][SIZE];

int square_num(int row, int col) { return 3*(row/3) + col/3; }

void backtracking(int idx) {
    if(idx == SIZE * SIZE) {
        complete = true; // (하나라도 찾으면 되기 때문에 곧바로 종료)
        return;
    }

    int row = idx / SIZE, col = idx % SIZE;
    if(sudoku[row][col]) return backtracking(idx+1); // 이미 채워진 값 pass

    for(int i = 1; i <= SIZE; i++) { // 비어있는 칸 1부터 9까지 넣어보기
        if(check1[row][i] || check2[col][i] || check3[square_num(row, col)][i]) continue; // i가 올 수 없는 경우 pass
        sudoku[row][col] = i; check1[row][i] = true; check2[col][i] = true; check3[square_num(row, col)][i] = true;
        backtracking(idx+1);
        if(complete) return;
        sudoku[row][col] = 0; check1[row][i] = false; check2[col][i] = false; check3[square_num(row, col)][i] = false;
    }
}

int main() {
    for(int i = 0; i < SIZE; i++) { // 스도쿠 입력받기
        for(int j = 0; j < SIZE; j++) {
            cin >> sudoku[i][j];

            if(sudoku[i][j]) {
                check1[i][sudoku[i][j]] = true; // i행
                check2[j][sudoku[i][j]] = true; // j열
                check3[square_num(i, j)][sudoku[i][j]] = true; // 3x3 정사각형
            }
        }
    }

    backtracking(0);
    for(int i = 0; i < SIZE; i++) { // 완성한 스도쿠 출력
        for(int j = 0; j < SIZE; j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}