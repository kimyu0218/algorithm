#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e6 + 1;
typedef pair<int, int> pi;

int prim(int v, int start, vector<vector<pi>> graph) {
    int sum = 0;
    vector<bool> visited(v+1, false); // 정점 방문 여부
    vector<int> dist(v+1, INF); // 각 정점까지 비용

    priority_queue<pi, vector<pi>, greater<>> pq;
    pq.push({0, start}); // 시작점
    dist[start] = 0;

    while(!pq.empty()) {
        auto[curr_w, curr] = pq.top(); pq.pop();

        if(visited[curr]) { // 이미 확인한 정점 pass
            continue;
        }
        visited[curr] = true; // 방문 체크
        sum += curr_w;

        for(auto[next_w, next]: graph[curr]) {
            // 미방문 정점이고 더 짧은 가중치 발견
            if(!visited[next] && dist[next] > next_w) {
                dist[next] = next_w;
                pq.push({next_w, next});
            }
        }
    }
    return sum;
}

int main() {
    int v, e, a, b, c;
    cin >> v >> e;

    vector<vector<pi>> graph(v+1, vector<pi> (0));
    while(e--) { // 간선 정보 입력
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    cout << prim(v, 1, graph);
    return 0;
}