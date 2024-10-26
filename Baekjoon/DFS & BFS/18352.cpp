#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int UNVISITED = -1;

vector<int> solution(int k, int x, vector<vector<int>> graph) {
    int n = graph.size() - 1;
    vector<int> result;
    vector<int> dist (n + 1, UNVISITED);
    queue<int> q;
    
    dist[x] = 0;
    q.push(x);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int i = 0; i < graph[node].size(); i++) {
            int new_node = graph[node][i];
            
            if(dist[new_node] != UNVISITED) {
                continue;
            }
            dist[new_node] = dist[node] + 1;
            q.push(new_node);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(dist[i] == k) {
            result.push_back(i);
        }
    }
    
    if(result.size() == 0) {
        return { -1 };
    }
    return result;
}

int main() {
    int n, m, k, x, a, b;
    vector<vector<int>> graph;
    
    cin >> n >> m >> k >> x;
    
    graph.assign(n + 1, vector<int> (0));
    while(m--) {
        cin >> a >> b;
        
        graph[a].push_back(b);
    }
    
    vector<int> result = solution(k, x, graph);
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}