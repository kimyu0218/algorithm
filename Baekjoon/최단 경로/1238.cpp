#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int INF = 1e5;

vector<int> dijkstra(int x, int n, vector<vector<pi>> adj_list) {
    vector<int> dist(n, INF);
    priority_queue<pi, vector<pi>, greater<>> pq;

    dist[x - 1] = 0;
    pq.push({0, x - 1});

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

int solution(int x, vector<vector<pi>> adj_list, vector<vector<pi>> rev_adj_list) {
    int result = 0;
    int n = adj_list.size();

    vector<int> to_x = dijkstra(x, n, rev_adj_list);
    vector<int> from_x = dijkstra(x, n, adj_list);

    for(int i = 0; i < n; i++) {
        result = max(result, to_x[i] + from_x[i]);
    }
    return result;
}

int main() {
    int n, m, x, s, e, t;
    vector<vector<pi>> adj_list;
    vector<vector<pi>> rev_adj_list;

    cin >> n >> m >> x;

    adj_list.assign(n, vector<pi>(0));
    rev_adj_list.assign(n, vector<pi>(0));

    while(m--) {
        cin >> s >> e >> t;

        adj_list[s - 1].push_back({e - 1, t});
        rev_adj_list[e - 1].push_back({s - 1, t});
    }

    cout << solution(x, adj_list, rev_adj_list);
    return 0;
}