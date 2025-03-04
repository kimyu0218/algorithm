#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int n, vector<int> indegree, vector<vector<int>> graph) {
    vector<int> result; // 순서 저장하는 벡터
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!indegree[i]) { // 진입 차수가 0인 경우
            q.push(i);
            result.push_back(i);
        }
    }

    while(!q.empty()) {
        int node = q.front(); q.pop();

        for(int i = 0; i < graph[node].size(); i++) { // node 다음 순서 탐색
            int next = graph[node][i];
            indegree[next]--; // 진입 차수 감소
            if(!indegree[next]) { // 진입 차수가 0인 경우
                q.push(next);
                result.push_back(next);
            }
        }
    }

    if(result.size() != n) { // 순서를 정하는 것이 불가능한 경우
        result = {0};
    }
    return result;
}

int main() {
    int n, m, p, x, y;
    cin >> n >> m;

    vector<int> indegree (n+1, 0);
    vector<vector<int>> graph (n+1, vector<int> (0));

    while(m--) {
        cin >> p >> x;
        while(--p) { // (순서 : x -> y)
            cin >> y;
            indegree[y]++;
            graph[x].push_back(y);
            x = y;
        }
    }

    vector<int> result = topologicalSort(n, indegree, graph);
    for(int i = 0; i < result.size(); i++) { // 결과 출력
        cout << result[i] << '\n';
    }
    return 0;
}