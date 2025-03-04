#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = -1e8 * 25;

ll solution(vector<int> p) {
    int n = p.size();
    vector<ll> dp (n + 1, INF);
    
    dp[0] = p[0];
    dp[n] = max(dp[n], dp[0]);
    for(int i = 1; i < n; i++) {
        dp[i] = max((ll) p[i], dp[i - 1] + p[i]);
        dp[n] = max(dp[n], dp[i]);
    }
    return dp[n];
}

int main() {
    int n;
    vector<int> p;
    
    while(true) {
        cin >> n;
        
        if(n == 0) {
            break;
        }
        
        p.assign(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        
        cout << solution(p) << '\n';
    }
    return 0;
}