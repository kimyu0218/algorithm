#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int n, vector<int> &indegree,  vector<vector<int>> &graph) {
    vector<int> result(n+1, 0); // 과목별 이수 학기 저장

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!indegree[i]) { // 진입 차수가 0인 경우
            q.push(i);
            result[i] = 1;
        }
    }

    while(!q.empty()) {
        int node = q.front(); q.pop();

        for(int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            indegree[next]--;

            if(!indegree[next]) { // 진입 차수가 0인 경우
                q.push(next);
                result[next] = result[node] + 1;
            }
        }
    }
    return result;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<int> indegree(n+1, 0);
    vector<vector<int>> graph(n+1, vector<int> (0));

    while(m--) { // 선수 과목 입력
        cin >> a >> b;
        indegree[b]++;
        graph[a].push_back(b); // (a 다음에 b 수강 가능)
    }

    vector<int> result = topologicalSort(n, indegree, graph);
    for(int i = 1; i <= n; i++) { // 결과 출력
        cout << result[i] << ' ';
    }
    return 0;
}