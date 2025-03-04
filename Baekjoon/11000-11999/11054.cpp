#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

vector<int> lis(int n) {
    vector<int> dp(n, 0); // dp[i] : 0부터 i까지 가장 긴 증가하는 수열 길이
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = i-1; j >= 0; j--) { // (i: 뒷번호, j: 앞번호)
            // 앞번호보다 뒷번호가 더 커야 함 -> j보다 i가 더 커야 함
            if(a[i] <= a[j]) continue; // 증가하지 않는 경우 pass
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return dp;
}

vector<int> rev_lis(int n) {
    vector<int> dp(n, 0); // dp[i] : n-1부터 i까지 가장 긴 증가하는 수열 길이
    for(int i = n-1; i >= 0; i--) {
        dp[i] = max(dp[i], 1);
        for(int j = i-1; j >= 0; j--) { // (i: 뒷번호, j: 앞번호)
            // 앞번호가 뒷번호가 더 커야 함 -> i보다 j가 더 커야 함
            if(a[i] >= a[j]) continue; // 감소하지 않는 경우 pass
            dp[j] = max(dp[j], dp[i] + 1);
        }
    }
    return dp;
}

int main() {
    int n;
    cin >> n;

    a.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> inc = lis(n);
    vector<int> dec = rev_lis(n);

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, inc[i] + dec[i] - 1);
    cout << ans;
    return 0;
}