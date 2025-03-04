#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 1;

int solution(int n, int k, vector<int> coin) {
    vector<int> dp(k + 1, INF);

    for(int i = 0; i < n; i++) {
        int v = coin[i];
        dp[v] = 1;

        for(int j = v + 1; j <= k; j++) {
            int u = dp[j - v];
            if(u == INF) {
                continue;
            }
            dp[j] = min(dp[j], u + dp[v]);
        }
    }
    return dp[k] == INF ? -1 : dp[k];
}

int main() {
    int n, k;
    vector<int> coin;

    cin >> n >> k;

    coin.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    cout << solution(n, k, coin);
    return 0;
}