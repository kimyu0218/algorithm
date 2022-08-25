#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> edge;

vector<int> dfs(int v, int n) {
    vector<int> result;

    vector<bool> visited (n+1, false); // 노드 방문 여부 체크
    stack<int> s; // (dfs : 스택 이용)

    visited[v] = true; s.push(v); // 시작 노드 방문
    result.push_back(v);

    while(!s.empty()) {
        int node = s.top();

        bool find = false;
        for(int i = 0; i < edge[node].size(); i++) {
            int node2 = edge[node][i];
            // 아직 방문하지 않은 노드 && node와 연결된 정점인 경우
            if(!visited[node2]) {
                visited[node2] = true; s.push(node2);
                result.push_back(node2);
                find = true; break; // 1. 더 깊게 탐색 -> 더 이상 node와 연결된 정점 찾을 필요 없음
            }
        }
        // 2. 더 깊게 탐색 불가 -> 이전 node로 돌아가기
        if(!find) s.pop();
    }
    return result;
}

vector<int> bfs(int v, int n) {
    vector<int> result;

    vector<bool> visited (n+1, false); // 노드 방문 여부 체크
    queue<int> q; // (bfs : 큐 이용)

    visited[v] = true; q.push(v); // 시작 노드 방문
    while(!q.empty()) {
        int node = q.front(); q.pop();
        result.push_back(node);
        for(int i = 0; i < edge[node].size(); i++) {
            int node2 = edge[node][i];
            if(!visited[node2]) {
                visited[node2] = true; q.push(node2);
            }
        }
    }
    return result;
}

int main() {
    int n, m, v; // 정점 개수, 간선 개수
    cin >> n >> m >> v;

    edge.assign(n+1, vector<int>(0, 0));

    int n1, n2;
    while(m--) { // 간선 정보 입력
        cin >> n1 >> n2;
        // 양방향
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }

    for(int i = 1; i <= n; i++)
        sort(edge[i].begin(), edge[i].end());

    vector<int> dfs_result = dfs(v, n);
    vector<int> bfs_result = bfs(v, n);

    for(int i = 0; i < dfs_result.size(); i++) cout << dfs_result[i] << ' ';
    cout << '\n';
    for(int i = 0; i < bfs_result.size(); i++) cout << bfs_result[i] << ' ';
    return 0;
}