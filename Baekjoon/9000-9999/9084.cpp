#include <iostream>
#include <vector>

using namespace std;

int make_money(vector<int> coin, int n, int m) {
    vector<int> dp(m + 1, 0);

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= m; j++)
            dp[j] += dp[j - coin[i]]; // (j+coin[i])원에서 coin[i] 더하기
    }
    return dp[m];
}

int main() {
    int t, n, m;
    cin >> t; // 테스트케이스

    while(t--) {
        cin >> n;
        vector<int> coin(n, 0);
        for(int i = 0; i < n; i++)
            cin >> coin[i]; // N가지 동전
        cin >> m;
        cout << make_money(coin, n, m) << '\n';
    }
    return 0;
}