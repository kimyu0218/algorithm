#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();

    if(n == 1) {
        return sticker[0];
    }

    vector<int> dp(n, 0);

    // 1. 0번째 스티커 붙이기
    dp[0] = dp[1] = sticker[0];
    for(int i = 2; i < n-1; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
        dp[n] = max(dp[n], dp[i]);
    }
    answer = max(answer, dp[n-2]);

    // 2. n-1번째 스티커 붙이기
    dp[0] = 0;
    dp[1] = sticker[1];
    for(int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    }
    answer = max(answer, dp[n-1]);

    return answer;
}