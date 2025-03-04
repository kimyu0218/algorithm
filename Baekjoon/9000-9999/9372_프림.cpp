#include <iostream>
#include <queue>

using namespace std;

int prim(int n, int start, vector<vector<int>> &graph) {
    int cnt = 0; // 비행기 개수 저장
    queue<int> q;
    vector<bool> visited(n+1, false); // 방문 여부 저장

    q.push(start); // 시작점
    visited[start] = true;

    while(!q.empty()) {
        int curr = q.front(); q.pop();

        for(int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];
            if(!visited[next]) { // 아직 방문하지 않은 국가 발견
                visited[next] = true;
                q.push(next);
                cnt++; // (curr -> next)로 가는 비행기 이용
            }
        }
    }
    return cnt;
}

int main() {
    int t, n, m, a, b;
    cin >> t;

    while(t--) { // 테스트 케이스
        cin >> n >> m;

        vector<vector<int>> graph(n+1, vector<int> (0));

        while(m--) { // 비행기 정보 입력
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cout << prim(n, 1, graph) << '\n';
    }
    return 0;
}