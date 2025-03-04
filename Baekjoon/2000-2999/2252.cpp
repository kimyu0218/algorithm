#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) { // 위상 정렬
    vector<int> result;
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(!indegree[i]) { // 진입 차수가 0인 경우
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front(); q.pop();

        result.push_back(node);
        for(int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            indegree[next]--;
            if(!indegree[next]) { // 진입 차수가 0인 경우
                q.push(next);
            }
        }
    }
    return result;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<int> indegree (n+1, 0); // 각 정점의 진입 차수
    vector<vector<int>> graph(n+1, vector<int> (0)); // 인접 리스트
    while(m--) {
        cin >> a >> b;
        indegree[b]++; // a 다음 b 줄 서기 가능
        graph[a].push_back(b);
    }

    vector<int> result = topologicalSort(n, indegree, graph);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}