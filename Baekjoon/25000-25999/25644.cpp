#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    vector<int> dp (n + 1, 0);
    
    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i], a[i] - a[i - 1] + dp[i - 1]);
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
    
    cout << solution(a);
    return 0;
}