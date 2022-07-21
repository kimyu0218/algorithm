#include <iostream>

using namespace std;

const int MAX = 15;
int n, result = 0;
int check[MAX];

bool possible(int num) { // 이미 배치된 퀸들과 공격 불가 상태인가
    int idx = 0;
    while(idx < num) {
        // 1. 같은 행 검사 (idx행과 num행에 들어있는 행 정보가 같은가)
        // 2. 같은 대각선 검사
        if(check[num] == check[idx] || abs(check[num] - check[idx]) == (num - idx))
            return false;
        idx++;
    }
    return true;
}

// 공격 불가 조건 : 가로, 세로, 대각선에 말을 놓으면 안된다
void backtracking(int cnt) { // (cnt : 퀸 수)
    if(cnt == n) { // n개 놓기 성공
        result++;
        return;
    }

    for(int i = 0; i < n; i++) { // (i : 열)
        check[cnt] = i; // (i, cnt)에 퀸 배치
        if(possible(cnt)) backtracking(cnt+1);
    }
}

int main() {
    cin >> n;

    backtracking(0);
    cout << result;
    return 0;
}