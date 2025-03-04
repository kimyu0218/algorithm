#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 7;
int num[MAX], arr[MAX];

void backtracking(int cnt, int n, int m) {
    if(cnt == m) { // 기저 조건
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        arr[cnt] = num[i];
        backtracking(cnt+1, n, m);
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