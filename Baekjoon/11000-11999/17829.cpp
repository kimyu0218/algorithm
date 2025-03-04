#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> matrix;
matrix cnn;

int divide(int row, int col, int size) { // (size == 한 변의 길이)
    if(size == 1) return cnn[row][col]; // conquer

    // divide
    vector<int> result;
    int sub = size / 2;
    for(int i = row; i < row + size; i += sub) {
        for(int j = col; j < col + size; j += sub)
            result.push_back(divide(i, j, sub));
    }

    // combine : 두 번째로 큰 수 구하기
    sort(result.begin(), result.end(), greater<>());
    return result[1];
}

int main() {
    int n;
    cin >> n;

    cnn.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> cnn[i][j];
    }

    cout << divide(0, 0, n);
    return 0;
}