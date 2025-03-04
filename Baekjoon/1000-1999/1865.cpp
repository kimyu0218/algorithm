#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> ti;
const int INF = 1e6 * 5;

vector<int> bellman_ford(int s, int n, vector<ti> &edges) {
    vector<int> dist(n+1, 0);
    dist[s] = 0; // 시작 위치

    for(int i = 1; i <= n; i++) {
        bool renew = false;
        for(int j = 0; j < edges.size(); j++) {
            int u = get<0>(edges[j]);
            int v = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if(dist[u] == INF) continue; // 아직 시작지점에서 u지점까지 경로 찾지 못함
            int new_weight = w + dist[u];
            if(dist[v] > new_weight) {
                if(i == n) return {INF + 1}; // 1. 음의 사이클 발견 -> 시간 줄어듦
                dist[v] = new_weight;
                renew = true;
            }
        }
        if(!renew) break; // 2. 음의 사이클 발견 못함 -> 시간 줄어들지 않음
    }
    return dist;
}

int main() {
    int tc, n, m, w, s, e, t;
    cin >> tc;

    while(tc--) { // 테스트 케이스
        cin >> n >> m >> w;

        vector<ti> edges;
        while(m--) { // 도로 정보 입력
            cin >> s >> e >> t;
            // (무방향 도로 == 양방향 도로)
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        while(w--) { // 웜홀 정보 입력력
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }
        // (시작점이 따로 주어지지 않음 -> 0에서 모든 정점까지 갈 수 있다고 가정)
        vector<int> dist = bellman_ford(0, n, edges);
        if(dist[0] == INF + 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}