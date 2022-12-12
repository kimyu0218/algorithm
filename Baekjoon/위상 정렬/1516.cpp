#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

vector<int> topologicalSort(int n, vector<int> &time, vector<int> &indegree, vector<vector<int>> &graph) {
    vector<int> result(n+1, 0); // 각 건물이 완성되는데 걸리는 시간

    priority_queue<pi> pq;
    for(int i = 1; i <= n; i++) {
        if(!indegree[i]) { // 진입 차수가 0인 경우
            result[i] = time[i];
            pq.push({time[i] , i});
        }
    }

    while(!pq.empty()) {
        int node = pq.top().second; pq.pop();

        for(int i = 0; i < graph[node].size(); i++) { // node의 후속 작업 탐색
            int next = graph[node][i];
            indegree[next]--;
            result[next] = max(result[next], result[node] + time[next]);

            if(!indegree[next]) { // 진입 차수가 0인 경우
                pq.push({result[next], next});
            }
        }
    }
    return result;
}

int main() {
    int n, x;
    cin >> n;

    vector<int> time(n+1, 0), indegree(n+1, 0);
    vector<vector<int>> graph(n+1, vector<int> (0));

    for(int i = 1; i <= n; i++) {
        cin >> time[i];
        while(true) {
            cin >> x; // (i 작업의 선행 작업 x)
            if(x == -1) { // 종료 조건
                break;
            }
            indegree[i]++;
            graph[x].push_back(i);
        }
    }

    vector<int> result = topologicalSort(n, time, indegree, graph);
    for(int i = 1; i <= n; i++) { // 결과 출력
        cout << result[i] << '\n';
    }
    return 0;
}