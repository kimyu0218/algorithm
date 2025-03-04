#include <iostream>
#include <vector>

using namespace std;

bool is_tree;
vector<bool> visited;
vector<vector<int>> graph;

void dfs(int node, int parent) {
    if(visited[node]) { // 이미 방문한 정점 (=사이클 발생)
        is_tree = false;
        return;
    }

    visited[node] = true; // 방문 check
    for(int i = 0; i < graph[node].size(); i++) {
        if(graph[node][i] != parent) // 자식 노드 탐색
            dfs(graph[node][i], node);
    }
}

void print_result(int tc, int tree_cnt) {
    string prefix = "Case " + to_string(tc) + ": ";
    if(tree_cnt == 0) cout << prefix << "No trees.\n";
    else if(tree_cnt == 1) cout << prefix << "There is one tree.\n";
    else cout << prefix << "A forest of " << tree_cnt << " trees.\n";
}

int main() {
    int n, m, a, b, tc = 0;
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        graph.assign(n+1, vector<int> (0));
        visited.assign(n+1, false);
        while(m--) { // 무방향 그래프 (부모 자식 관계 모름)
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int tree_cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(visited[i]) continue; // 이미 방문한 정점 pass
            is_tree = true;
            dfs(i, -1); // i가 루트 노드인 트리 탐색
            if(is_tree) tree_cnt++;
        }
        print_result(++tc, tree_cnt);
    }
    return 0;
}