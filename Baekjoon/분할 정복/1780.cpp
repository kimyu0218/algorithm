#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;

bool same_color(int row, int col, int color, int size) { // 같은 색깔인가
    for(int i = row; i < row + size; i++) {
        for(int j = col; j < col + size; j++) {
            if(paper[i][j] != color) return false;
        }
    }
    return true;
}

vector<int> divide(int row, int col, int size) {
    vector<int> ans = {0, 0, 0}; // (0: -1 종이 개수, 1: 0 종이 개수, 2: 1 종이 개수)

    if(size == 1) { // conquer
        ans[paper[row][col]+1]++;
        return ans;
    }

    int color = paper[row][col];
    // 1. 종이 그대로 사용
    if(same_color(row, col, color, size)) ans[color+1]++;
    // 2. 종이 자르기
    else {
        int sub = size/3;
        for(int i = row; i < row + size; i += sub) {
            for(int j = col; j < col + size; j += sub) {
                vector<int> sub_ans = divide(i, j, sub);
                ans[0] += sub_ans[0];
                ans[1] += sub_ans[1];
                ans[2] += sub_ans[2];
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    paper.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) { // 종이 입력
        for(int j = 0; j < n; j++)
            cin >> paper[i][j];
    }

    vector<int> ans = divide(0, 0, n);
    for(int i = 0; i < 3; i++)
        cout << ans[i] << '\n';
    return 0;
}