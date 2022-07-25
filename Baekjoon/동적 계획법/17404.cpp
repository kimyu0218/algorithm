#include <iostream>

using namespace std;
const int SIZE = 1000, MAX = 1000000;
int cost[SIZE+1][3], dp[SIZE+1][3];

int min_cost(int n, int color) {
    for(int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }

    int result = MAX + 1;
    for(int i = 0; i < 3; i++) { // i : 집 색상
        if(i != color) result = min(result, dp[n][i]); // 첫번째 집 색상과 n번째 집 색상이 다른 경우
    }
    return result;
}

int main() {
    int n, result = MAX+1;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    for(int i = 0; i < 3; i++) { // i : 집 색상
        for(int j = 0; j < 3; j++) {
            if(i == j) dp[1][j] = cost[1][j];
            else dp[1][j] = MAX + 1;
        }
        result = min(result, min_cost(n, i)); // 첫번째 집이 i 색상일 때 최솟값
    }
    cout << result;
    return 0;
}