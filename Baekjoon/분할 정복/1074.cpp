#include <iostream>
#include <cmath>

using namespace std;

int r, c, answer;
int order = 0;

void divide(int row, int col, int size) {
    if(size == 1) { // conquer
        if(row == r && col == c) answer = order;
        order++; return;
    }

    // divide
    if((row <= r && r < row + size) && (col <= c && c < col + size)) {
        int sub = size/2;
        divide(row, col, sub);
        divide(row, col + sub, sub);
        divide(row + sub, col, sub);
        divide(row + sub, col+ sub, sub);
    }
    else order += size * size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n >> r >> c;

    int size = pow(2, n); // 한 변의 길이
    divide(0, 0, size);
    cout << answer;
    return 0;
}