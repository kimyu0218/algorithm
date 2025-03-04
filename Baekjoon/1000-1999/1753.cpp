#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int INF = 2 * 1e5;

vector<int> dijkstra(int v, int k, vector<vector<pi>> adj_list) {
    vector<int> dist(v, INF);
    priority_queue<pi, vector<pi>, greater<>> pq;

    dist[k - 1] = 0;
    pq.push({0, k - 1});

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

vector<string> solution(int k, vector<vector<pi>> adj_list) {
    int v = adj_list.size();
    vector<string> result(v, "");
    vector<int> dist = dijkstra(v, k, adj_list);

    for(int i = 0; i < v; i++) {
        result[i] = (dist[i] == INF ? "INF" : to_string(dist[i]));
    }
    return result;
}

int main() {
    int v, e, k, eu, ev, ew;
    vector<vector<pi>> adj_list;

    cin >> v >> e >> k;

    adj_list.assign(v, vector<pi> (0));
    while(e--) {
        cin >> eu >> ev >> ew;
        adj_list[eu - 1].push_back({ev - 1, ew});
    }

    vector<string> result = solution(k, adj_list);

    for(int i = 0; i < v; i++) {
        cout << result[i] << '\n';
    }
    return 0;
}