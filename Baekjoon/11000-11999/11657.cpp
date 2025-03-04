#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<int, int, int> ti;
const int INF = 1e6 * 5;
vector<ti> edges;

vector<ll> bellman_ford(int n, int m, int start) {
    vector<ll> dist(n+1, INF); // 시작점에서 모든 정점까지 최단경로

    // 시작 위치 초기화
    dist[start] = 0;

    for(int i = 1; i <= n; i++) {
        bool renew = false; // 갱신 여부 저장
        for(int j = 0; j < m; j++) { // 최단 경로 갱신
            // u에서 v로 가는 가중치 w
            int u = get<0>(edges[j]);
            int v = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if(dist[u] == INF) continue; // 아직 시작점에서 u로 가는 경로 발견 못함
            ll new_weight = w + dist[u];
            if(dist[v] > new_weight) {
                if(i == n) return {INF + 1}; // (정점이 n개일 때 간선은 최대 n-1개 -> 간선이 n개이면 음의 사이클)
                dist[v] = new_weight;
                renew = true;
            }
        }
        if(!renew) break; // 값이 더 이상 갱신되지 않음 (== 음의 사이클 없음)
    }
    return dist;
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;

    edges.assign(m, {0, 0, 0});
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        // (방향 그래프)
        edges[i] = {a, b, c};
    }

    vector<ll> ans = bellman_ford(n, m, 1);
    if(ans[0] == INF + 1) { // 음의 사이클 발생
        cout << -1;
        return 0;
    }
    for(int i = 2; i <= n; i++) {
        if(ans[i] == INF) cout << -1 << '\n';
        else cout << ans[i] << '\n';
    }
    return 0;
}