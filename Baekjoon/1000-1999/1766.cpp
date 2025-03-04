#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int n, vector<int> indegree, vector<vector<int>> graph) {
    vector<int> result; // 문제 순서 저장
    priority_queue<int, vector<int>, greater<>> pq; // (난이도 낮은 문제부터 풀이 시작)

    for(int i = 1; i <= n; i++) {
        if(!indegree[i]) { // 진입 차수가 0인 경우
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int node = pq.top(); pq.pop();
        result.push_back(node);

        for(int i = 0; i < graph[node].size(); i++) { // node 다음에 풀 수 있는 문제 탐색
            int next = graph[node][i];
            indegree[next]--;
            if(!indegree[next]) { // 진입 차수가 0인 경우
                pq.push(next);
            }
        }
    }
    return result;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<int> indegree (n+1, 0);
    vector<vector<int>> graph (n+1, vector<int> (0));

    while(m--) { // (a 다음에 b를 푸는 것이 좋다)
        cin >> a >> b;
        indegree[b]++;
        graph[a].push_back(b);
    }

    vector<int> result = topologicalSort(n, indegree, graph);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}