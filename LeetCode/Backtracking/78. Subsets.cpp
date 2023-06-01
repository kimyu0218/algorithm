class Solution {
public:
    void backtracking(int idx, int cnt, int n, vector<int> subset, vector<int> &nums, vector<vector<int>> &answer) {
        if(cnt <= n) {
            answer.push_back(subset);
        }
        if(cnt == n) {
            return;
        }

        for(int i = idx; i < n; i++) {
            vector<int> tmp = subset;
            tmp.push_back(nums[i]);
            backtracking(i+1, cnt+1, n, tmp, nums, answer);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        int n = nums.size();
        backtracking(0, 0, n, {}, nums, answer);
        return answer;
    }
};