#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e6, SIZE = 15;

int cntCase(int n, int l, int r, int x, vector<int> &a) {
    int cnt = 0;
    for(int i = 1; i < (1 << n); i++) { // i : 경우의 수
        int select = 0, sum = 0, min_num = MAX, max_num = 1;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) { // j번재 문제 고름
                select++;
                sum += a[j];
                max_num = max(max_num, a[j]);
                min_num = min(min_num, a[j]);
            }
        }
        if(select >= 2 && sum >= l && sum <= r && max_num - min_num >= x) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, l, r, x;
    vector<int> a;

    cin >> n >> l >> r >> x;
    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << cntCase(n, l, r, x, a);
    return 0;
}