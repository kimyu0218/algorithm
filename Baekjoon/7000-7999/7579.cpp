#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e4;

int getMByte(int n, int mem, vector<int> &m, vector<int> &c) {
    vector<int> dp (MAX+1, 0); // dp[i] : i 바이트로 확보할 수 있는 메모리 바이트

    for(int i = 0; i < n; i++) {
        for(int j = MAX; j >= c[i]; j--) {
            dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
        }
    }

    for(int i = 0; i <= MAX; i++) {
        if(dp[i] >= mem) { // i 바이트로 mem 바이트 이상 확보 가능한 경우
            return i;
        }
    }
}

int main() {
    int n, mem; // 앱 개수, 메모리 바이트
    vector<int> m, c;

    cin >> n >> mem;
    m.assign(n, 0);
    c.assign(n, 0);

    for(int i = 0; i < n; i++) { // 앱이 사용하는 메모리 바이트 수 입력
        cin >> m[i];
    }
    for(int i = 0; i < n; i++) { // 앱 비활성화 비용 입력
        cin >> c[i];
    }

    cout << getMByte(n, mem, m, c);
    return 0;
}