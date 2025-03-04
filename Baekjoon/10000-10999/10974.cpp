#include <iostream>

using namespace std;

const int MAX = 8;
int arr[MAX];
bool visited[MAX+1];

void backtracking(int cnt, int n) {
    if(cnt == n) { // 기저 조건 : 순열 완성
        for(int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(visited[i]) { // 이미 사용한 숫자 pass
            continue;
        }
        visited[i] = true; // 방문 체크
        arr[cnt] = i;
        backtracking(cnt+1, n);
        visited[i] = false; // 방문 체크 취소
    }
}

int main() {
    int n;

    cin >> n;
    backtracking(0, n);
    return 0;
}