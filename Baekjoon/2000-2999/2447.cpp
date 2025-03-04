#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> star;

void divide(int row, int col, int size) {
    if(size == 1) { // conquer : 별 찍고 stop
        star[row][col] = '*';
        return;
    }

    // divide
    int sub = size / 3;
    for(int i = row; i < row + size; i += sub) {
        for(int j = col; j < col + size; j += sub) {
            if(i >= row + sub && i < row + 2 * sub && j >= col + sub && j < col + 2 * sub) continue; // 공백 pass
            divide(i, j, sub);
        }
    }
}

int main() {
    int n;
    cin >> n;

    star.assign(n, vector<char> (n, ' '));
    divide(0, 0, n);

    for(int i = 0; i < n; i++) { // 별 출력
        for(int j = 0; j < n; j++)
            cout << star[i][j];
        cout << '\n';
    }
    return 0;
}