#include <iostream>
#include <vector>

using namespace std;

const int COL = 4;

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size();

    vector<vector<int>> dp(n, vector<int> (COL, 0));
    for(int j = 0; j < COL; j++) {
        dp[0][j] = land[0][j];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < COL; j++) {
            for(int k = 0; k < COL; k++) {
                if(j == k) {
                    continue;
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + land[i][j]);
            }
        }
    }

    for(int j = 0; j < COL; j++) {
        answer = max(answer, dp[n - 1][j]);
    }
    return answer;
}