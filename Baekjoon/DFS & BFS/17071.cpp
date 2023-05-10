#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
const int MAX = 5 * 1e5;
bool visited[MAX+1][2]; // (0 : 짝수. 1 : 홀수)

int move(int n) { // 동생이 이동해야 하는 칸의 개수
    return n * (n+1) / 2;
}

int bfs(int n, int k) {
    queue<pi> q; // 수빈이의 현위치

    q.push({n, 0}); // 수빈 위치 push
    visited[n][0] = true;

    while(!q.empty()) {
        int x = q.front().first; // 수빈이 이동한 위치
        int sec = q.front().second;
        q.pop();
        
        int nk = k + move(sec);
        if(nk > MAX) { // 좌표 벗어나는 경우
            return -1;
        }
        if(visited[nk][sec%2]) { // 동생 찾음
            return sec;
        }
        sec++; // 1초 지남
        
        // 1. 걷기
        if(x-1 >= 0 && !visited[x-1][sec%2]) {
            q.push({x-1, sec});
            visited[x-1][sec%2] = true;
        }
        if(x+1 <= MAX && !visited[x+1][sec%2]) {
            q.push({x+1, sec});
            visited[x+1][sec%2] = true;
        }
        // 2. 순간 이동
        if(2*x <= MAX && !visited[2*x][sec%2]) {
            q.push({2*x, sec});
            visited[2*x][sec%2] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    cout << bfs(n, k);
    return 0;
}