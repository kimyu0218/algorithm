class Solution {
public:
    vector<bool> visited;
    vector<int> perm;

    void backtracking(int cnt, int n, vector<int> &nums, vector<vector<int>> &answer) {
        if(cnt == n) {
            answer.push_back(perm);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                continue;
            }
            visited[i] = true;
            perm[cnt] = nums[i];
            backtracking(cnt+1, n, nums, answer);
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;

        int n = nums.size();
        visited.assign(n, false);
        perm.assign(n, 0);

        backtracking(0, n, nums, answer);
        return answer;
    }
};