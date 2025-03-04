#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int INF = 16 * 1e5;

vector<int> dijkstra(int start, int n, vector<vector<pi>> adj_list) {
    vector<int> dist(n, INF);
    priority_queue<pi, vector<pi>, greater<>> pq;

    dist[start - 1] = 0;
    pq.push({0, start - 1});

    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        for(int i = 0; i < adj_list[node].size(); i++) {
            int next = adj_list[node][i].first;
            int w = adj_list[node][i].second;

            if(dist[next] > dist[node] + w) {
                dist[next] = dist[node] + w;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

int solution(int v1, int v2, vector<vector<pi>> adj_list) {
    int n = adj_list.size();

    vector<int> from_start = dijkstra(1, n, adj_list);
    vector<int> from_v1 = dijkstra(v1, n, adj_list);
    vector<int> from_v2 = dijkstra(v2, n, adj_list);

    int v1_to_v2 = from_start[v1 - 1] + from_v1[v2 - 1] + from_v2[n - 1];
    int v2_to_v1 = from_start[v2 - 1] + from_v2[v1 - 1] + from_v1[n - 1];

    int result = min(v1_to_v2, v2_to_v1);
    return result >= INF ? -1 : result;
}

int main() {
    int n, e, a, b, c, v1, v2;
    vector<vector<pi>> adj_list;

    cin >> n >> e;

    adj_list.assign(n, vector<pi>(0));
    while(e--) {
        cin >> a >> b >> c;

        adj_list[a - 1].push_back({b - 1, c});
        adj_list[b - 1].push_back({a - 1, c});
    }

    cin >> v1 >> v2;

    cout << solution(v1, v2, adj_list);
    return 0;
}