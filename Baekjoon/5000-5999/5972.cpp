#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int INF = 1e7 * 5 + 1;

int dijkstra(int n, vector<vector<pi>> road) {
    vector<int> dist (n+1, INF);
    priority_queue<pi, vector<pi>, greater<>> pq; // (first : 해당 헛간까지 마주치는 소의 수, second : 헛간 번호)

    // 시작 정점 세팅
    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        int c = pq.top().first; // 소의 수
        int node = pq.top().second; // 헛간 번호
        pq.pop();

        if(node == n) { // 찬흥에게 택배 전달 완료
            return c;
        }

        for(int i = 0; i < road[node].size(); i++) {
            int next = road[node][i].first; // 연결된 헛간의 번호
            int next_c = road[node][i].second; // 만나는 소의 수
            if(dist[next] > c + next_c) { // dist 갱신
                dist[next] = c + next_c;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    int n, m, a, b, c;
    vector<vector<pi>> road;

    cin >> n >> m;
    road.assign(n+1, vector<pi> ());
    while(m--) {
       cin >> a >> b >> c;
       // 양방향 길
       road[a].push_back({b, c});
       road[b].push_back({a, c});
    }

    cout << dijkstra(n, road);
    return 0;
}