class Solution {
public:
    void dfs(int node, int n, vector<bool> &visited, vector<vector<int>> &isConnected) {
        visited[node] = true;
        for(int i = 0; i < n; i++) {
            if(i == node) {
                continue;
            }
            if(isConnected[node][i] && !visited[i]) {
                dfs(i, n, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0, n = isConnected.size();
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                cnt++;
                dfs(i, n, visited, isConnected);
            }
        }
        return cnt;
    }
};