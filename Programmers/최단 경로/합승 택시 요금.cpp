#include <string>
#include <vector>

using namespace std;

const int INF = 1e7 * 2;
vector<vector<int>> graph;

void initialize_graph(int n, vector<vector<int>> fares) {
    graph.assign(n+1, vector<int> (n+1, INF));
    for(int i = 1; i <= n; i++) graph[i][i] = 0;

    for(int i = 0; i < fares.size(); i++) {
        int u = fares[i][0], v = fares[i][1], w = fares[i][2];
        // u에서 v, v에서 u로 이동하기 위해 필요한 비용 w
        graph[u][v] = w;
        graph[v][u] = w;
    }
}

void floyd_warshall(int n, int s) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int dist = graph[i][k] + graph[k][j];
                if(graph[i][j] > dist) graph[i][j] = dist;
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    initialize_graph(n, fares);
    floyd_warshall(n, s);
    answer = graph[s][a] + graph[s][b]; // 1. 각자 타기
    for(int i = 1; i <= n; i++) // 2. i 지점까지 합승하기
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    return answer;
}