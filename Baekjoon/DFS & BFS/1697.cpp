#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;
int position[MAX+1];
bool visited[MAX+1];

void move(int prev, int next, queue<int> &q) {
    visited[next] = true;
    position[next] = position[prev] + 1;
    q.push(next);
}

int bfs(int n, int k) {
    queue<int> q;
    q.push(n); // 시작점 push

    while(!q.empty()) {
        int x = q.front(); q.pop();
        visited[x] = true; // 방문 check

        if(x == k) break;

        if(x-1 >= 0 && x-1 <= MAX && !visited[x-1]) move(x, x-1, q);
        if(x+1 >= 0 && x+1 <= MAX && !visited[x+1]) move(x, x+1, q);
        if(2*x >= 0 && 2*x <= MAX && !visited[2*x]) move(x, 2*x, q);
    }
    return position[k];
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << bfs(n, k);
    return 0;
}