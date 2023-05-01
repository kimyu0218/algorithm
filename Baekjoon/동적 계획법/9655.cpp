#include <iostream>
#include <vector>

using namespace std;

const int SK = 1, CY = 2; // (각각 상근, 창영의 돌을 의미한다)

string stoneGame(int n) { // 돌 게임 승자 반환
    if(n == 1 || n == 3) {
        return "SK";
    }
    if(n == 2 || n == 4) {
        return "CY";
    }
    vector<int> dp(n+1, 0);
    dp[1] = dp[3] = SK;
    dp[2] = dp[4] = CY;
    for(int i = 5; i <= n; i++) {
        dp[i] = dp[i-2];
    }
    return (dp[n] == SK) ? "SK" : "CY";
}

int main() {
    int n;
    cin >> n;
    cout << stoneGame(n);
    return 0;
}