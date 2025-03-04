#include <iostream>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
const int SIZE = 10;
bool visited[SIZE+1][SIZE+1]; // 방문 여부
int board[SIZE+1][SIZE+1];

pair<int, int> cor(int num) { // num -> (row, col) 형태로 변환
    int row = (num % 10) ? (num/10 + 1) : num/10;
    int col = (num % 10) ? (num % 10) : 10;
    return {row, col};
}

void bfs(int start, map<int, int> move) {
    queue<pi> q;
    q.push({start, 0}); // 시작 지점 push

    while(!q.empty()) {
        int num = q.front().first; // 칸 번호
        int cnt = q.front().second; // 주사위 굴린 횟수
        q.pop();

        if(move[num]) num = move[num]; // 순간이동 (사다리 or 뱀)
        pair<int, int> c = cor(num);
        int row = c.first, col = c.second;
        if(visited[row][col]) continue; // 이미 방문한 곳 pass

        // 방문 체크
        visited[row][col] = true; board[row][col] = cnt;
        if(num == SIZE * SIZE) break; // 100번 칸 도착

        for(int i = 1; i <= 6; i++) // (i : 주사위 눈)
            q.push({num+i, cnt+1});
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m;

    map<int, int> move; // 순간이동 정보
    while(n--) { // 사다리 입력
        cin >> x >> y;
        move[x] = y;
    }
    while(m--) { // 뱀 입력
        cin >> x >> y;
        move[x] = y;
    }

    bfs(1, move);
    cout << board[SIZE][SIZE];
    return 0;
}