#include <iostream>

using namespace std;

const int SIZE = 1000, MAX = 1000000;

int cost[SIZE+1][3], dp[SIZE+1][3];

int min_cost(int n) {
    for(int i = 1; i <= n; i++) { // (i : 집 순서)
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }

    int result = MAX+1;
    for(int i = 0; i < 3; i++) result = min(dp[n][i], result);
    return result;
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    cout << min_cost(n);
    return 0;
}