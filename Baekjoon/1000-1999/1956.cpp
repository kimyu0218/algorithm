#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e6 * 4 + 1; // (사이클이므로 최대 v개 만큼의 간선을 이용함)
vector<vector<int>> graph;

void floyd_warshall(int n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int dist = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], dist);
            }
        }
    }
}

int main() {
    int v, e, a, b, c;
    cin >> v >> e;

    graph.assign(v+1, vector<int>(v+1, INF));
    while(e--) {
        cin >> a >> b >> c;
        // (일방 통행 도로 == 단방향 그래프)
        // (a == b일 수 있음)
        graph[a][b] = c;
    }

    floyd_warshall(v);
    int ans = INF;
    for(int i = 1; i <= v; i++) {
        if(graph[i][i] == INF) continue;
        ans = min(ans, graph[i][i]);
    }

    if(ans == INF) cout << -1;
    else cout << ans;
    return 0;
}