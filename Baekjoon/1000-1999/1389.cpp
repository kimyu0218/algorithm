#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e2 + 1;

typedef pair<int, int> pi;

vector<vector<int>> floyd_warshall(int n, vector<pi> relations) {
    int m = relations.size();
    vector<vector<int>> dist (n + 1, vector<int> (n + 1, INF));
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int u = relations[i].first;
        int v = relations[i].second;

        dist[u][v] = min(dist[u][v], 1);
        dist[v][u] = min(dist[v][u], 1);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int d = dist[i][k] + dist[k][j];
                dist[i][j] = min(dist[i][j], d);
            }
        }
    }
    return dist;
}

int solution(int n, vector<pi> relations) {
    int answer = 1;
    vector<vector<int>> dist = floyd_warshall(n, relations);

    int min_sum = INF * n;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                continue;
            }
            sum += dist[i][j];
        }
        if(sum < min_sum) {
            min_sum = sum;
            answer = i;
        }
    }
    return answer;
}

int main() {
    int n, m;
    vector<pi> relations;

    cin >> n >> m;

    relations.assign(m, {0, 0});
    for(int i = 0; i < m; i++) {
        cin >> relations[i].first >> relations[i].second;
    }

    cout << solution(n, relations);
    return 0;
}