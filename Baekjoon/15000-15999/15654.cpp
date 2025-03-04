#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 8;

bool visited[MAX];
int num[MAX], arr[MAX];

void backtracking(int cnt, int n, int m) {
    if(cnt == m) { // 기저조건
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i]) {
            continue;
        }
        arr[cnt] = num[i];
        visited[i] = true; // 방문 체크
        backtracking(cnt+1, n, m);
        visited[i] = false; // 방문 취소
    }
}

int main() {
    int n, m;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n); // 오름차순 정렬
    backtracking(0, n, m);
    return 0;
}