#include <iostream>
#include <vector>

using namespace std;

int reverseLcs(int n, vector<int> &a) { // 가장 긴 감소하는 부분 수열 길이 반환
    vector<int> dp (n+1, 1);
    for(int i = 0; i < n; i++) { // i : 뒤
        for(int j = 0; j < i; j++) { // j : 앞
            if(a[i] < a[j]) { // 감소하는 수열 발견
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        dp[n] = max(dp[n], dp[i]);
    }
    return dp[n];
}

int main() {
    int n;
    vector<int> a;

    cin >> n;
    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << reverseLcs(n, a);
    return 0;
}