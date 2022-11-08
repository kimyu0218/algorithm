#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e6;

int cntPassword(int n, string &s) {
    if(s[0] == '0') return 0; // 첫 시작이 0인 경우, 암호 만들 수 없음

    vector<int> dp(n+1, 0);

    s = ' ' + s; // (인덱스 맞추기 위해 앞에 공백 더하기)
    dp[0] = dp[1] = 1; // 첫번째 암호 해석 경우
    for(int i = 2; i <= n; i++) {
        if(s[i] == '0' && (s[i-1] < '1' || s[i-1] > '2')) { // 암호 해독 불가
            return 0;
        }
        if(s[i] != '0') { // 한 자리 수
            dp[i] += dp[i-1];
        }
        if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) { // 두 자리 수
            dp[i] += dp[i-2];
        }
        dp[i] %= MOD;
    }
    return dp[n];
}

int main() {
    string s;
    cin >> s;

    cout << cntPassword(s.length(), s);
    return 0;
}