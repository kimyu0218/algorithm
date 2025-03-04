#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int MAX = 8;
int num[MAX], arr[MAX];

void backtracking(int idx, int cnt, int n, int m) {
    if(cnt == m) { // 기저 조건
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if(idx == n) { // 기저 조건
        return;
    }

    for(int i = idx; i < n; i++) {
        arr[cnt] = num[i];
        backtracking(i, cnt+1, n, m);
    }
}

int main() {
    int n, m, x, idx = 0;
    set<int> s;

    cin >> n >> m;
    while(n--) {
        cin >> x;
        if(s.find(x) == s.end()) { // 새로운 숫자가 등장한 경우
            s.insert(x);
            num[idx++] = x;
        }
    }

    sort(num, num + idx);
    backtracking(0, 0, idx, m);
    return 0;
}