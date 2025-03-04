#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int answer = 0, check_node;
vector<bool> visited;
vector<vector<pi>> tree;

void dfs(int node, int dist) {
    visited[node] = true; // 방문 체크
    if(dist > answer) {
        answer = dist;
        check_node = node;
    }

    for(int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i].first;
        int weight = tree[node][i].second;
        if(visited[next]) { // 이미 방문한 노드 pass
            continue;
        }
        dfs(next, dist + weight);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int v, n1, n2, w;

    cin >> v;
    tree.assign(v+1, vector<pi> (0));
    for(int i = 0; i < v; i++) {
        cin >> n1;
        while(true) { // n1과 연결된 정점 입력
            cin >> n2;
            if(n2 == -1) { // 마지막
                break;
            }
            cin >> w;
            tree[n1].push_back({n2, w});
        }
    }

    visited.assign(v+1, false);
    dfs(1, 0);

    visited.assign(v+1, false);
    dfs(check_node, 0);

    cout << answer;
    return 0;
}