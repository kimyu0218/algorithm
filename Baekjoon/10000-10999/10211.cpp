#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> x) {
    int result = x[0];
    int n = x.size();
    vector<int> dp (n + 1, 0);
    
    dp[0] = x[0];
    for(int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + x[i];
        result = max(result, dp[i]);
        
        for(int j = i - 1; j >= 0; j--) {
            result = max(result, dp[i] - dp[j]);
        }
    }
    return result;
}

int main() {
    int t, n;
    vector<int> x;
    
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        x.assign(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }
        
        cout << solution(x) << '\n';
    }
    return 0;
}