#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;
vector<vector<ci>> graph;

int dfs(int node, int parent) {
    if(graph[node].size() == 0) return 0;

    int subtree = 0;
    for(int i = 0; i < graph[node].size(); i++){
        if(graph[node][i].first == parent) continue;
        subtree = max(subtree, graph[node][i].second + dfs(graph[node][i].first, node));
    }

    return subtree;
}

int main() {
    int n, u, v, w;
    cin >> n;

    graph.assign(n+1, vector<ci> (0));
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dfs(i, -1));
    cout << ans;
    return 0;
}