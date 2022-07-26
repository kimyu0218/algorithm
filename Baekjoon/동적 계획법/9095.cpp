#include <iostream>

using namespace std;

const int MAX = 10;
int dp[MAX+1];

void set_dp() {
    dp[1] = dp[2] = dp[3] = 1; // 1, 2, 3을 하나씩 이용하여 1, 2, 3 만들기

    // dp[k] : 이미 1, 2, 3의 합으로 이루어진 수 (k는 항상 양수!)
    // 이미 1, 2, 3의 합으로 이루어진 수에 히나의 1, 2, 3 더하기
    for(int i = 1; i <= MAX; i++) {
        if(i-1 >= 1) dp[i] += dp[i-1]; // 1 더하기
        if(i-2 >= 1) dp[i] += dp[i-2]; // 2 더하기
        if(i-3 >= 1) dp[i] += dp[i-3]; // 3 더하기
    }
}

int main() {
    int t, n;
    cin >> t;

    set_dp();
    while(t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}