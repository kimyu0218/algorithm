#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> consult; // (first: time, second : profit)
vector<int> dp;

int max_profit(int n) {
    for(int i = 1; i <= n; i++) { // (i : 일자)
        dp[i] = max(dp[i], dp[i-1]);
        int restart_date = i + consult[i].first; // 다시 상담을 진행할 수 있는 날짜
        if(restart_date <= n+1) dp[restart_date] = max(dp[restart_date], dp[i] + consult[i].second); // 상담 진행
    }

    dp[n+1] = max(dp[n], dp[n+1]);
    return dp[n+1];
}

int main() {
    int n;
    cin >> n;

    dp.assign(n+2, 0);
    consult.assign(n+2, {1, 0});
    for(int i = 1; i <= n; i++)
        cin >> consult[i].first >> consult[i].second;

    cout << max_profit(n);
    return 0;
}