#include <iostream>

using namespace std;

const int SIZE = 100, DENOMINATOR = 1000000000;
int dp[SIZE+1][10];

int stair_num(int n) {
    for(int i = 1; i <= 9; i++) dp[1][i] = 1; // 첫번째 자리수 세팅 (0은 포함하지 않는다)

    for(int i = 2; i <= n; i++) { // (i : 자릿수)
        dp[i][0] = dp[i-1][1] % DENOMINATOR; // (0과 계단 수를 이룰 수 있는 건 1뿐)
        for(int j = 1; j <= 8; j++) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % DENOMINATOR;
        dp[i][9] = dp[i-1][8] % DENOMINATOR; // (9와 계단 수를 이룰 수 있는 건 8뿐)
    }

    long long result = 0;
    for(int i = 0; i <= 9; i++) result += dp[n][i];
    return result % DENOMINATOR;
}

int main() {
    int n;
    cin >> n;

    cout << stair_num(n);
    return 0;
}