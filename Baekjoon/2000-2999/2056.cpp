#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int topologicalSort(int n, vector<int> &indegree, vector<int> &time, vector<vector<int>> &graph) {
    int t = 0; // 작업 완료 시간

    priority_queue<pi, vector<pi>, greater<>> pq;
    for(int i = 1; i <= n; i++) {
        if(!indegree[i]) { // 진입 차수가 0인 경우
            pq.push({time[i], i});
        }
        t = max(t, time[i]);
    }

    while(!pq.empty()) {
        auto[node_w, node] = pq.top(); pq.pop();

        for(int i = 0; i < graph[node].size(); i++) { // node의 후속 작업
            int next = graph[node][i];
            indegree[next]--;

            if(!indegree[next]) { // 진입 차수가 0인 경우
                int next_w = node_w + time[next];
                pq.push({next_w, next});
                t = max(t, next_w);
            }
        }
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, x;
    cin >> n;

    vector<int> indegree(n+1, 0), time(n+1, 0);
    vector<vector<int>> graph(n+1, vector<int> (0));

    for(int i = 1; i <= n; i++) { // i번째 작업
        cin >> time[i] >> m;
        indegree[i] = m;

        for(int j = 0; j < m; j++) { // i번째 작업의 선행 작업 x
            cin >> x;
            graph[x].push_back(i);
        }
    }

    cout << topologicalSort(n, indegree, time, graph);
    return 0;
}