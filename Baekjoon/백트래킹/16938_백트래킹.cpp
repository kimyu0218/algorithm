#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e6, SIZE = 15;

int answer = 0;
int arr[SIZE];

void backtracking(int idx, int cnt, int m, int n, int l, int r, int x, vector<int> &a) {
    if(cnt == m) { // 문제 m개 고르기
        int min_num = MAX, max_num = 1, sum = 0;
        for(int i = 0; i < m; i++) {
            sum += arr[i];
            min_num = min(min_num, arr[i]);
            max_num = max(max_num, arr[i]);
        }
        if(sum >= l && sum <= r && max_num - min_num >= x) {
            answer++;
        }
        return;
    }

    for(int i = idx; i < n; i++) {
        arr[cnt] = a[i];
        backtracking(i+1, cnt+1, m, n, l, r, x, a);
    }
}

int main() {
    int n, l, r, x;
    vector<int> a;

    cin >> n >> l >> r >> x;
    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 2; i <= n; i++) {
        backtracking(0, 0, i, n, l, r, x, a);
    }
    cout << answer;
    return 0;
}