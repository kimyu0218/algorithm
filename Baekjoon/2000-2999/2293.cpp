#include <iostream>
#include <vector>

using namespace std;

int cnt_case(int k, int n, vector<int> coin) {
    vector<int> dp(k+1, 0); // dp[i] : i원을 만드는 경우의 수

    dp[0] = 1; // 0원을 만드는 경우의 수는 동전을 사용하지 않는 것
    for(int i = 0; i < n; i++) {
        for(int j = coin[i]; j <= k; j++) // j원 만들기
            dp[j] += dp[j - coin[i]];
    }
    return dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coin(n, 0);
    for(int i = 0; i < n; i++) // 동전 가치 입력
        cin >> coin[i];

    cout << cnt_case(k, n, coin);
    return 0;
}