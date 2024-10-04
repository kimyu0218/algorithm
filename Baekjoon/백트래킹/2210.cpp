#include <iostream>
#include <set>

using namespace std;

const int SIZE = 5;
const int LEN = 6;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

char board[SIZE][SIZE];
set<string> s;

void backtracking(int row, int col, string num) {
    if(num.length() == LEN) {
        s.insert(num);
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if(nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE) {
            continue;
        }
        backtracking(nr, nc, num + board[nr][nc]);
    }
}

void brute_force() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            backtracking(i, j, "");
        }
    }
}

int solution() {
    brute_force();
    
    return s.size();
}

int main() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << solution();
    return 0;
}