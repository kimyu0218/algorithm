#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<bool> leaf;
vector<vector<int>> graph;

void dfs(int node, int del) {
    if(graph[node].size() == 0) return; // 리프 노드 발견 -> 탐색 중단

    for(int i = 0; i < graph[node].size(); i++) {
        if(graph[node][i] != del) { // 하위 노드가 있다면 리프 노드 아님
            dfs(graph[node][i], del);
            leaf[node] = false;
        }
    }
}

void delete_subtree(int node) { // node의 서브 트리 지우기
    // (서브 트리를 지운다 = 정점을 지운다 = 리프 노드가 아니다)
    leaf[node] = false;
    if(graph[node].size() == 0) return;

    for(int i = 0; i < graph[node].size(); i++)
        delete_subtree(graph[node][i]);
}

int main() {
    int n, del;
    cin >> n;

    parent.assign(n, 0); // (parent[i] : i의 부모 노드)
    leaf.assign(n, true); // (모든 정점 리프 노드라고 가정)
    graph.assign(n, vector<int> (0));
    for(int i = 0; i < n; i++) {
        cin >> parent[i];
        if(parent[i] != -1) graph[parent[i]].push_back(i); // 루트 노드가 아닌 경우 간선 표기
    }

    cin >> del;
    delete_subtree(del); // del의 서브 트리 제거

    for(int i = 0; i < n; i++) {
        if(parent[i] == -1) dfs(i, del); // 루트 노드 발견
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(leaf[i]) cnt++;
    }
    cout << cnt;
    return 0;
}