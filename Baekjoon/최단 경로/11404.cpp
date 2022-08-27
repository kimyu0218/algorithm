#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e7;
vector<vector<int>> graph;

void floyd_warshall(int n) {
    for(int k = 1; k <= n; k++) { // k 도시를 경유하자
        for(int i = 1; i <= n; i++) { // 시작점 : i 도시
            for(int j = 1; j <= n; j++) { // 도착점 : j 도시
                int dist = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], dist);
            }
        }
    }
}
int main() {
    int n, m, a, b, c;
    cin >> n >> m;

    graph.assign(n+1, vector<int> (n+1, INF));
    for(int i = 1; i <= n; i++)
        graph[i][i] = 0;

    while(m--) { // 버스 정보
        cin >> a >> b >> c;
        // (a 도시와 b 도시를 연결하는 노선은 하나가 아닐 수 있음)
        graph[a][b] = min(graph[a][b], c);
    }

    floyd_warshall(n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(graph[i][j] == INF) cout << 0 << ' ';
            else cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}