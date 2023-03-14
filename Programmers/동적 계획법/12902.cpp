#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;

ll solution(int n) {
    vector<ll> dp(n+1, 0); // dp[i] : 가로 길이가 i일 때, 채우는 방법의 수

    dp[0] = 1;
    dp[1] = 0; // 1x3은 만들 수 없음
    dp[2] = 3; // 2x3을 만드는 경우의 수
    for(int i = 4; i <= n; i+=2) {
        dp[i] = dp[i-2] * 3; // 2x3 옆에 붙이기
        for(int j = i-4; j >= 0; j-=2) { // 4x2와 4x1 2개 붙이기
            dp[i] += dp[j] * 2;
        }
        dp[i] %= MOD;
    }
    return dp[n];
}