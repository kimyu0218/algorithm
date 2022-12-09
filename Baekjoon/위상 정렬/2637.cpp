#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

vector<pi> topologicalSort(int n, vector<int> indegree, vector<vector<pi>> graph) {
    vector<pi> result; // (first: 기본 제품 번호, second: 해당 제품 개수)
    vector<int> basic; // 기본 제품 번호 저장
    vector<int> dp (n+1, 0); // dp[i] : n 제품을 만들기 위해 필요한 i 제품 수

    queue<int> q;
    q.push(n); dp[n] = 1; // n제품 push (n제품은 하나 만들기 시작)

    while(!q.empty()) {
        int node = q.front(); q.pop();

        if(graph[node].size() == 0) { // node 제품이 기본 제품인 경우
            basic.push_back(node);
        }

        for(int i = 0; i < graph[node].size(); i++) { // node 제품의 부속 제품 탐색
            int next = graph[node][i].first;
            int k = graph[node][i].second; // node 제품을 만들기 위해 next 제품 k개가 필요함

            dp[next] += (dp[node] * k);
            indegree[next]--;
            if(!indegree[next]) { // 진입 차수가 0인 경우
                q.push(next);
            }
        }
    }

    sort(basic.begin(), basic.end()); // 기본 제품 번호 오름차순 정렬
    for(int i = 0; i < basic.size(); i++) {
        result.push_back({basic[i], dp[basic[i]]});
    }
    return result;
}

int main() {
    int n, m, x, y, k;
    cin >> n >> m;

    vector<int> indegree (n+1, 0);
    vector<vector<pi>> graph (n+1, vector<pi> (0));

    while(m--) { // x 만드는 데 k개의 y 필요
        cin >> x >> y >> k;
        indegree[y]++;
        graph[x].push_back({y, k});
    }

    vector<pi> result = topologicalSort(n, indegree, graph);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i].first << ' ' << result[i].second << '\n';
    }
    return 0;
}