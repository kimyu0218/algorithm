#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int INF = 1e5 * 2;

vector<int> dijkstra(int n, int k, vector<vector<pi>> adj_list) {
    vector<int> dist (n + 1, INF);
    priority_queue<pi, vector<pi>, greater<>> pq;
    
    pq.push({0, k});
    
    while(!pq.empty()) {
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        
        if(dist[v] <= w) {
            continue;
        }
        dist[v] = w;
        
        for(int i = 0; i < adj_list[v].size(); i++) {
            int nw = w + adj_list[v][i].first;
            int u = adj_list[v][i].second;
            
            if(dist[u] > nw) {
                pq.push({nw, u});
            }
        }
    }
    return dist;
}

vector<string> solution(int n, int k, vector<vector<pi>> adj_list) {
    vector<string> answer (n, "");
    vector<int> dist = dijkstra(n, k, adj_list);
    
    for(int i = 1; i <= n; i++) {
        answer[i - 1] = (dist[i] == INF) ? "INF" : to_string(dist[i]);
    }
    return answer;
}

int main() {
    int v, e, k, eu, ev, ew;
    vector<vector<pi>> adj_list;
    
    cin >> v >> e >> k;
    
    adj_list.assign(v + 1, vector<pi> (0));
    while(e--) {
        cin >> eu >> ev >> ew;
        
        adj_list[eu].push_back({ew, ev});
    }
    
    vector<string> answer = solution(v, k, adj_list);
    
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}