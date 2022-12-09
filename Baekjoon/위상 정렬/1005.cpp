#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int topologicalSort(int n, int w, vector<int> &d, vector<int> &indegree, vector<vector<int>> &graph) {
    queue<int> q;
    vector<int> dp(n + 1, 0); // 현재 건물을 짓기까지 걸린 최소 시간

    for (int i = 1; i <= n; i++) {
        dp[i] = d[i]; // dp 배열 초기화
        if (!indegree[i]) { // 진입 차수가 0인 경우
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            indegree[next]--; 
            if (!indegree[next]) { // 진입 차수가 0인 경우
                q.push(next);
            }
            dp[next] = max(dp[next], dp[node] + d[next]);
        }
    }
    return dp[w];
}

int main() {
    int t, n, k, x, y, w;
    cin >> t;

    while(t--) {
        cin >> n >> k;

        vector<int> d(n+1, 0);
        vector<int> indegree (n+1, 0);
        vector<vector<int>> graph(n+1, vector<int> (0)); // 인접 리스트

        for(int i = 1; i <= n; i++) { // 소요 시간 입력
            cin >> d[i];
        }

        while(k--) { // 건설 순서 입력
            cin >> x >> y;
            indegree[y]++;
            graph[x].push_back(y);
        }

        cin >> w;
        cout << topologicalSort(n, w, d, indegree, graph) << '\n';
    }
    return 0;
}