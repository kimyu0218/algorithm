#include <iostream>

using namespace std;

const int SIZE = 10;
const int INF = -1e6 - 1;

int answer = INF;

bool visited[SIZE][SIZE];
int board[SIZE][SIZE];

void backtracking(int idx, int cnt, int k, int sum, int n, int m) {
    if(cnt == k) {
        answer = max(answer, sum);
        return;
    }
    if(idx == n * m) {
        return;
    }

    int row = idx / m;
    int col = idx % m;
    int score = board[row][col];

    if(!(row && visited[row - 1][col]) && !(col && visited[row][col - 1])) {
        visited[row][col] = true;
        backtracking(idx + 1, cnt + 1, k, sum + score, n, m);
        visited[row][col] = false;
    }
    backtracking(idx + 1, cnt, k, sum, n, m);
}

int solution(int n, int m, int k) {
    backtracking(0, 0, k, 0, n, m);
    return answer;
}

int main() {
    int n, m, k;

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    cout << solution(n, m, k);
    return 0;
}