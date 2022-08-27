#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

void floyd_warshall(int n) {
    for(int k = 1; k <= n; k++) { // k 사건
        for(int i = 1; i <= n; i++) { // i 사건
            for(int j = 1; j <= n; j++) { // j 사건
                // 1. i가 j보다 먼저 일어났다 (i > k > j)
                if(graph[i][k] == -1 && graph[k][j] == -1) {
                    graph[i][j] = -1;
                    graph[j][i] = 1;
                }
                // 2. j가 i보다 먼저 일어났다 (j > k > i)
                else if(graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                    graph[j][i] = -1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, prev, next, s;
    cin >> n >> k;

    graph.assign(n+1, vector<int> (n+1, 0));
    while(k--) { // 사건 전후 관계 입력
        cin >> prev >> next;
        graph[prev][next] = -1;
        graph[next][prev] = 1;
    }

    floyd_warshall(n);

    cin >> s;
    while(s--) {
        cin >> prev >> next;
        cout << graph[prev][next] << '\n';
    }
    return 0;
}