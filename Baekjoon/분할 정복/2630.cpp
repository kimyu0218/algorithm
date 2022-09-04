#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper; // 색종이

bool conquer(int n, int row, int col, int color) { // 모두 같은 색인가?
    for(int i = row; i < row+n; i++) {
        for(int j = col; j < col+n; j++) {
            if(paper[i][j] != color) return false;
        }
    }
    return true;
}

vector<int> divide(int n, int row, int col) {
    vector<int> combine = {0, 0}; // (0: white, 1: blue)

    if(conquer(n, row, col, paper[row][col])) {
        combine[paper[row][col]]++;
        return combine;
    }

    // divide : 문제 분할
    int sub = n / 2;
    for(int i = 0; i <= sub; i += sub) {
        for(int j = 0; j <= sub; j += sub) {
            vector<int> sub_problem = divide(sub, row+i, col+j);
            combine[0] += sub_problem[0];
            combine[1] += sub_problem[1];
        }
    }
    return combine;
}


int main() {
    int n;
    cin >> n;

    paper.assign(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> paper[i][j];
    }

    vector<int> ans = divide(n, 0, 0);
    cout << ans[0] << '\n' << ans[1];
    return 0;
}