#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int max_sum(int n) {
    vector<int> dp (n+1, 0); // dp[i] : 1부터 i 사이 최대 연속합

    int ans = arr[1];
    for(int i = 1; i <= n; i++) {
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    arr.assign(n+1, 0);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    cout << max_sum(n);
    return 0;
}