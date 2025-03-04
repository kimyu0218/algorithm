#include <iostream>

using namespace std;
const int CNT = 10, INF = 1e9;

int answer = INF;
int arr[CNT][2];
int ingredient[CNT][2];

int tasteDiff(int m) {
    int s = 1, b = 0;
    for(int i = 0; i < m; i++) {
        s *= arr[i][0];
        b += arr[i][1];
    }
    return abs(s-b);
}

void backtracking(int idx, int cnt, int m, int n) {
    if(cnt == m) { // m개의 재료 선택 완료
        int diff = tasteDiff(m);
        answer = min(answer, diff);
        return;
    }

    for(int i = idx; i < n; i++) {
        arr[cnt][0] = ingredient[i][0];
        arr[cnt][1] = ingredient[i][1];
        backtracking(i+1, cnt+1, m, n);
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> ingredient[i][0] >> ingredient[i][1];
    }

    for(int i = 1; i <= n; i++) {
        backtracking(0, 0, i, n);
    }
    cout << answer;
    return 0;
}