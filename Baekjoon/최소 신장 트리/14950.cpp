#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> pi;

const int START = 1;

int prim(int n, int t, vector<vector<pi>> &graph) {
    int sum = 0, cost = 0;
    vector<bool> visited (n+1, false);
    priority_queue<pi, vector<pi>, greater<>> pq;

    pq.push({0, START});

    while(!pq.empty()) {
        int c = pq.top().first;
        int a = pq.top().second;
        pq.pop();

        if(visited[a]) {
            continue;
        }
        visited[a] = true;
        sum += (c + cost);
        if(a != START) { // 시작 정점이 아닌 경우, 경계 비용 t만큼 증가
            cost += t;
        }

        for(int i = 0; i < graph[a].size(); i++) {
            int b = graph[a][i].first;
            int new_c = graph[a][i].second;
            if(!visited[b]) { // 정복 가능한 도시 발견
                pq.push({new_c, b});
            }
        }
    }
    return sum;
}

int main() {
    int n, m, t, a, b, c;
    vector<vector<pi>> graph;

    cin >> n >> m >> t;
    graph.assign(n+1, vector<pi> (0));
    while(m--) {
        cin >> a >> b >> c;
        // 양방향 그래프
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cout << prim(n, t, graph);
    return 0;
}