class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n  = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > n) {
                n = nums[i];
            }
        }

        vector<int> dp(n+1, 0), freq(n+1, 0);
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        dp[1] = freq[1];
        for(int i = 2; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + i*freq[i]);
        }
        return dp[n];
    }
};