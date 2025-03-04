#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll solution(int n) {
    if(n <= 3) {
        return 1;
    }
    
    vector<ll> dp (n, 1);
    
    for(int i = 3; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
    return dp[n - 1];
}

int main() {
    int n;
    
    cin >> n;
    
    cout << solution(n);
    return 0;
}