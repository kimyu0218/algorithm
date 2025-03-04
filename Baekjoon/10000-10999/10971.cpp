#include <iostream>

using namespace std;

const int MAX = 10;

int result = 1e6 * MAX + 1;
int w[MAX][MAX];
bool visited[MAX];

void backtracking(int start, int prev, int cost, int cnt, int n) {
    if(cnt == n) {
        if(!w[prev][start]) {
            return;
        }
        result = min(result, cost + w[prev][start]);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!w[prev][i] || visited[i]) {
            continue;
        }
        visited[i] = true;
        backtracking(start, i, cost + w[prev][i], cnt + 1, n);
        visited[i] = false;
    }
}

int solution(int n) {
    for(int i = 0; i < n; i++) {
        visited[i] = true;
        backtracking(i, i, 0, 1, n);
        visited[i] = false;
    }
    return result;
}

int main() {
    int n;

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    cout << solution(n);
    return 0;
}