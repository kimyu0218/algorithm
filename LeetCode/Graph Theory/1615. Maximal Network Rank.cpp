class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        vector<vector<int>> edge(n, vector<int> (0));
        vector<vector<bool>> graph(n, vector<bool> (n, false));

        for(int i = 0; i < m; i++) {
            int a = roads[i][0], b = roads[i][1];
            edge[a].push_back(b);
            edge[b].push_back(a);
            graph[a][b] = graph[b][a] = true;
        }

        int answer = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                int rank = edge[i].size() + edge[j].size();
                if(graph[i][j]) {
                    rank--;
                }
                answer = max(answer, rank);
            }
        }
        return answer;
    }
};