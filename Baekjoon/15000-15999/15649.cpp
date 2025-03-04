#include <iostream>

using namespace std;

const int MAX = 8;

bool visited[MAX];
int result[MAX];

void solution(int idx, int n, int m) {
    if(idx == m) {
        for(int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(visited[i]) {
            continue;
        }
        visited[i] = true;
        result[idx] = i;
        solution(idx + 1, n, m);
        visited[i] = false;
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    solution(0, n, m);
    return 0;
}