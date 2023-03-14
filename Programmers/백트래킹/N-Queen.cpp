#include <string>
#include <vector>

using namespace std;

// (row를 고정한 상태로 col, left, right 상태 확인하기)
int backtracking(int r, int n, vector<bool> &col, vector<bool> &left, vector<bool> &right) { // N-Queen 만들기
    if(r == n) { // 기저 조건
        return 1;
    }

    int cnt = 0; // 방법의 개수
    for(int c = 0; c < n; c++) {
        if(!col[c] && !left[r+c] && !right[r-c+n]) {
            col[c] = left[r+c] = right[r-c+n] = true;
            cnt += backtracking(r+1, n, col, left, right);
            col[c] = left[r+c] = right[r-c+n] = false;
        }
    }
    return cnt;
}

int solution(int n) {
    vector<bool> col(n, false);
    vector<bool> left(n*2, false);
    vector<bool> right(n*2, false);

    return backtracking(0, n, col, left, right);
}