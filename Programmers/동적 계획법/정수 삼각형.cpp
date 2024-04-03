#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int n = triangle.size();
    vector<vector<int>> dp (n, vector<int> (0));
    for(int i = 0; i < n; i++) {
        dp[i].assign(i + 1, 0);
    }
    dp[0][0] = triangle[0][0];

    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];

        for(int j = 1; j < i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        answer = max(answer, dp[n - 1][i]);
    }
    return answer;
}