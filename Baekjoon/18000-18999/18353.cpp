#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> ap) {
    int n = ap.size();
    vector<int> dp (n + 1, 1);
    
    for(int i = 1; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(ap[i] >= ap[j]) {
                continue;
            }
            dp[i] = max(dp[i], dp[j] + 1);\
            dp[n] = max(dp[n], dp[i]);
        }
    }
    return n - dp[n];
}

int main() {
    int n;
    vector<int> ap;
    
    cin >> n;
    
    ap.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> ap[i];
    }
    
    cout << solution(ap);
    return 0;
}