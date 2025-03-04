#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int s, int n, vector<int> a) {
    vector<bool> visited (n+1, false); // 방문 여부 저장

    queue<int> q;
    q.push(s); visited[s] = true; // 시작점 push

    while(!q.empty()) {
        int node = q.front(); q.pop();
        int d = a[node]; // node에서 점프할 수 있는 거리

        if(node-d > 0 && !visited[node-d]) { // 왼쪽으로 이동 가능한 경우
            visited[node-d] = true;
            q.push(node-d);
        }
        if(node+d <= n && !visited[node+d]) { // 오른쪽으로 이동 가능한 경우
            visited[node+d] = true;
            q.push(node+d);
        }
    }

    // 방문 가능한 돌 개수 세기
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(visited[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, s;
    cin >> n;

    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> s;
    cout << bfs(s, n, a);
    return 0;
}