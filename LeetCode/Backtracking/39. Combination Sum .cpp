class Solution {
public:
    void backtracking(int idx, int n, int sum, int target, vector<int> comb, vector<int> &candidates, vector<vector<int>> &answer) {
        if(sum == target) {
            answer.push_back(comb);
            return;
        }
        for(int i = idx; i < n; i++) {
            if(sum + candidates[i] <= target) {
                vector<int> tmp = comb;
                tmp.push_back(candidates[i]);
                backtracking(i, n, sum + candidates[i], target, tmp, candidates, answer);
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        int n = candidates.size();
        backtracking(0, n, 0, target, {}, candidates, answer);
        return answer;
    }
};