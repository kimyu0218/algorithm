#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e7;
vector<vector<int>> graph;
vector<vector<int>> path; // path[u][v] : u에서 v로 가기 위해 가장 먼저 거쳐야 하는 정점

void floyd_warshall(int n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int dist = graph[i][k] + graph[k][j];
                if(graph[i][j] > dist) {
                    graph[i][j] = dist;
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}
int main() {
    int n, m, u, v, t;
    cin >> n >> m;

    graph.assign(n+1, vector<int> (n+1, INF));
    path.assign(n+1, vector<int> (n+1, 0));
    for(int i = 1; i <= n; i++)
        graph[i][i] = 0;

    while(m--) {
        cin >> u >> v >> t;

        // u에서 v, v에서 u로 가는 가중치는 t
        graph[u][v] = t;
        graph[v][u] = t;

        // u에서 v로 가기 위해 가장 먼저 거치는 경로
        path[u][v] = v;
        path[v][u] = u;
    }

    floyd_warshall(n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) cout << "- ";
            else cout << path[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}