#include <iostream>

using namespace std;

const int MAX = 300;
int stair[MAX], dp[MAX];

int step_up(int n) {
    dp[0] = stair[0]; dp[1] = stair[0] + stair[1];
    // 1. 두 칸 올라가기
    // 2. 한 칸 이동 (i-2 건너뛰기)
    for(int i = 2; i < n; i++)
        dp[i] = max(dp[i-2], dp[i-3] + stair[i-1]) + stair[i];
    return dp[n-1];
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) // 계단 점수 입력
        cin >> stair[i];

    cout << step_up(n);
    return 0;
}