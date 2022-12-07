#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int bfs(int n, vector<vector<int>> graph) {
    vector<bool> visited (n+1, false); // 방문 여부 저장

    queue<pi> q;
    q.push({1, 0}); visited[1] = true; // 상근이 방문 체크

    while(!q.empty()) {
        int node = q.front().first, step = q.front().second;
        q.pop();

        if(step == 2) { // 친구의 친구까지 초대 완료
            continue;
        }

        for(int i = 0; i < graph[node].size(); i++) { // 친구 조사
            int next = graph[node][i];
            if(!visited[next]) { // 친구 초대
                visited[next] = true;
                q.push({next, step+1});
            }
        }
    }

    // 결혼식이 초대할 동기 수 세기
    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(visited[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int> (0));
    while(m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << bfs(n, graph);
    return 0;
}