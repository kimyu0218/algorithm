#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e6 * 2;
typedef pair<int, int> ci;
vector<vector<ci>> graph;

vector<int> dijkstra(int n, int s) { // 최단거리 구하기
    vector<int> dist(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    // 시작 지점
    dist[s] = 0; pq.push({0, s});

    while(!pq.empty()) {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if(weight > dist[node]) continue; // 이미 방문한 노드 pass
        for(int i = 0; i < graph[node].size(); i++) {
            int new_node = graph[node][i].first;
            int new_weight = weight + graph[node][i].second;
            if(dist[new_node] > new_weight) { // 더 짧은 경로 발견
                dist[new_node] = new_weight;
                pq.push({new_weight, new_node});
            }
        }
    }
    return dist;
}

int main() {
    int test, n, m, t, s, g, h, a, b, d, x;
    cin >> test;

    while(test--) { // 테스트 케이스
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        graph.assign(n+1, vector<ci> (0));
        while(m--) { // 도로 입력
            cin >> a >> b >> d;
            // (양방향 도로)
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }

        vector<int> from_s = dijkstra(n, s), from_g = dijkstra(n, g), from_h = dijkstra(n, h);
        vector<int> dest; // 가능한 목적지 저장
        while(t--) { // 목적지 후보
            cin >> x;
            // s에서 x까지 최단 경로가 존재하고 g-h 교차로를 지나간 경우
            int case1 = from_s[g] + from_g[h] + from_h[x]; // 1. s -> g -> h -> n
            int case2 = from_s[h] + from_h[g] + from_g[x]; // 2. s -> h -> g -> n
            if(from_s[x] != INF && from_s[x] == min(case1, case2))
                dest.push_back(x);
        }
        sort(dest.begin(), dest.end());
        for(int i = 0; i < dest.size(); i++)
            cout << dest[i] << ' ';
        cout << '\n';
    }
    return 0;
}