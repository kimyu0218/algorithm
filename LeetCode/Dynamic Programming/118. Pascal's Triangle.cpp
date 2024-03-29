class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp (numRows, vector<int> (0));
        dp[0].push_back(1);

        for(int i = 1; i < numRows; i++) {
            dp[i].push_back(1);
            for(int j = 1; j < i; j++) {
                dp[i].push_back(dp[i-1][j-1] + dp[i-1][j]);
            }
            dp[i].push_back(1);
        }
        return dp;
    }
};