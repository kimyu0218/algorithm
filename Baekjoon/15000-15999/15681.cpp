#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> dp; // 서브 트리 정점 개수 저장하는 dp

int dfs(int node, int parent) {
    if(visited[node]) return 0; // 이미 방문한 노드 pass
    visited[node] = true; dp[node] = 1; // 방문 check (처음 방문한 노드이므로 리프 노드 상태)

    for(int i = 0; i < graph[node].size(); i++) { // 현재 노드와 연결된 간선 탐색
        if(graph[node][i] == parent) continue; // 부모 노드 pass
        dp[node] += dfs(graph[node][i], node); // 자식 노드의 정점 개수 더하기
    }
    return dp[node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, r, q, u, v;
    cin >> n >> r >> q;

    graph.assign(n+1, vector<int> (0)); // (graph[i] : i와 연결된 정점 리스트)
    visited.assign(n+1, false); // 방문 여부
    dp.assign(n+1, 0);

    for(int i = 0; i < n-1; i++) { // (트리 성질 : 정점이 n개이므로 간선은 n-1개)
        cin >> u >> v;
        // (부모 자식 관계 모름 -> 무방향 그래프)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(r, -1);
    while(q--) { // 쿼리
        cin >> u;
        cout << dp[u] << '\n';
    }
    return 0;
}