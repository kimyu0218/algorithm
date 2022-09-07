#include <iostream>
#include <vector>

using namespace std;

const int MIN = -1e7;
vector<int> temp;

int highest_temp(int n, int k) {
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++)
        dp[i] = dp[i-1] + temp[i];

    int ans = MIN;
    for(int i = 0; i <= n-k; i++)
        ans = max(ans, dp[i+k] - dp[i]);
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    temp.assign(n+1, 0);
    for(int i = 1; i <= n; i++)
        cin >> temp[i];

    cout << highest_temp(n, k);
    return 0;
}