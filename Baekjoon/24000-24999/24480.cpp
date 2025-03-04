#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;
vector<vector<int>> edge;
vector<int> order; // 노드 방문 순서

void dfs(int node) { // 깊이 우선 탐색 (재귀)
    if(order[node]) return; // 이미 방문한 노드 PASS

    // 방문 check
    order[node] = ++cnt;

    for(int i = 0; i < edge[node].size(); i++) {
        // 아직 방문하지 않았고 node와 연결된 정점
        int node2 = edge[node][i];
        if(!order[node2]) dfs(node2);
    }
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    edge.assign(n+1, vector<int>(0, 0));
    order.assign(n+1, 0);

    int u, v;
    while(m--) {
        cin >> u >> v;
        // (무방향 그래프)
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
        sort(edge[i].begin(), edge[i].end(), greater<>());

    dfs(r); // 깊이 우선 탐색 시작

    for(int i = 1; i <= n; i++) // 노드 방문 순서 출력
        cout << order[i] << '\n';
    return 0;
}