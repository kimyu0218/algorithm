#include <iostream>
#include <vector>

using namespace std;

vector<int> dp; // dp[k원] = 최소 동전수

int min_cnt(int n, int k) {
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= (i-1)/2 + 1; j++) {
            if(dp[j] == -1 || dp[i-j] == -1) continue; // i원과 i-j원을 만들 수 없는 경우 pass
            // i원을 만들 수 있는 경우
            if(dp[i] != -1) dp[i] = min(dp[i], dp[i-j] + dp[j]); // 1. 이전에 i원을 만든 이력이 있는 경우 동전 개수 최솟값 갱신
            else dp[i] = dp[i-j] + dp[j]; // 2. 이전에 i원을 만들지 못한 경우 동전 개수 입력
        }
    }
    return dp[k];
}

int main() {
    int n, k, coin;
    cin >> n >> k;

    dp.assign(k+1, -1); // 불가능으로 초기화
    for(int i = 1; i <= n; i++) { // 동전 가치 입력
        cin >> coin;
        dp[coin] = 1; // (동전 하나로 만들 수 있다)
    }

    cout << min_cnt(n, k);
    return 0;
}