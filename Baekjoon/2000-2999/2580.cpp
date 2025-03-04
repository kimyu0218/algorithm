#include <iostream>

using namespace std;

const int SIZE = 9;

bool complete = false;
int sudoku[SIZE][SIZE];
bool visited_row[SIZE][SIZE + 1];
bool visited_col[SIZE][SIZE + 1];
bool visited_square[SIZE][SIZE + 1];

int get_square_idx(int row, int col) {
    return (row / 3) * 3 + (col / 3);
}

void init_visited() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            int num = sudoku[i][j];
            int square = get_square_idx(i, j);
            visited_row[i][num] = visited_col[j][num] = visited_square[square][num] = true;
        }
    }
}

void backtracking(int idx) {
    if(idx == SIZE * SIZE) {
        complete = true;
        return;
    }

    int row = idx / SIZE;
    int col = idx % SIZE;
    int num = sudoku[row][col];

    if(num) {
        return backtracking(idx + 1);
    }

    int square = get_square_idx(row, col);
    for(int i = 1; i <= SIZE; i++) {
        if(visited_row[row][i] || visited_col[col][i] || visited_square[square][i]) {
            continue;
        }
        visited_row[row][i] = visited_col[col][i] = visited_square[square][i] = true;
        sudoku[row][col] = i;
        backtracking(idx + 1);
        if(complete) {
            return;
        }
        visited_row[row][i] = visited_col[col][i] = visited_square[square][i] = false;
        sudoku[row][col] = 0;
    }
}

void solution() {
    init_visited();
    backtracking(0);
}

int main() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> sudoku[i][j];
        }
    }

    solution();

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}