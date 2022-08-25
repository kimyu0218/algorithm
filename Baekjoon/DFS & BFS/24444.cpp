#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> edge;
vector<int> order; // 노드 방문 순서

void bfs(int r) {
    int cnt = 0;
    queue<int> q;

    // 시작 지점 방문
    order[r] = ++cnt; q.push(r);

    while(!q.empty()) {
        int node = q.front(); q.pop();
        for(int i = 0; i < edge[node].size(); i++) {
            int node2 = edge[node][i];
            if(!order[node2]) {
                order[node2] = ++cnt;
                q.push(node2);
            }
        }
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
        sort(edge[i].begin(), edge[i].end());

    bfs(r);

    for(int i = 1; i <= n; i++)
        cout << order[i] << '\n';
    return 0;
}