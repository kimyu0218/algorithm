#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, num, i, j;
    cin >> n >> m;

    vector<int> sum(n+1, 0);
    for(int i = 1; i <= n; i++) { // n개의 수 입력
        cin >> num;
        sum[i] = sum[i-1] + num;
    }

    while(m--) {
        cin >> i >> j;
        cout << sum[j] - sum[i-1] << '\n';
    }
    return 0;
}