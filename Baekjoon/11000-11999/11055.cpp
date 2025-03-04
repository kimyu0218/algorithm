#include <iostream>
#include <vector>

using namespace std;

int transformedLcs(int n, vector<int> &a) {
    vector<int> dp(n+1, 0); // dp[i] : i가 가장 큰 값인, 증가하는 부분 수열 중 가장 큰 합

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) { // 증가하는 부분 수열 발견
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += a[i]; // 자기 자신 더해주기
        dp[n] = max(dp[i], dp[n]);
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> a (n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << transformedLcs(n, a);
    return 0;
}