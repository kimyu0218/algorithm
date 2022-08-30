#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
vector<vector<ci>> graph;

int dfs(int node, int parent) {
    // 리프 노드 발견
    if(graph[node].size() == 1 && graph[node][0].first == parent) return graph[node][0].second;

    int len = 0, subtree = 0; // (len : parent와 node를 잇는 간선 길이, subtree : node의 하위 트리 최대 간선 합)
    for(int i = 0; i < graph[node].size(); i++) {
        if(graph[node][i].first == parent) len = graph[node][i].second;
        else subtree = max(subtree, dfs(graph[node][i].first, node));
    }
    return len + subtree;
}

int bfs(int r, int n) {
    int len = 0;
    queue<int> q;

    vector<bool> visited(n+1, false);
    visited[r] = true; q.push(r); // 시작 노드

    while(!q.empty()) {
        int node = q.front(); q.pop();

        int tmp = 0, new_node, new_weight; // (tmp : node부터 new_node까지 길이 저장)
        for(int i = 0; i < graph[node].size(); i++) {
            new_node = graph[node][i].first;
            new_weight = graph[node][i].second;

            if(!visited[new_node]) {
                visited[new_node] = true; q.push(new_node);
                // 기가 노드 발견 : node에 연결된 가지가 2개 이상
                if(q.size() >= 2) return len;
                tmp += new_weight;
            }
        }
        len += tmp;
    }
    return len;
}

int main() {
    int n, r, a, b, d;
    cin >> n >> r;

    graph.assign(n+1, vector<ci> (0));
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b >> d;
        // (부모 자식 관계 모름 -> 무방향 그래프)
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }

    int max_len = dfs(r, -1); // 루트 노드부터 리프 노드까지 탐색 -> 가장 긴 길이 반환
    int trunk = bfs(r, n); // 루트 노드부터 기가 노드까지 길이 반환 -> 줄기 길이
    cout << trunk << ' ' << max_len - trunk;
    return 0;
}