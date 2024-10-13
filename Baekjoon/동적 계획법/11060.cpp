#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    vector<int> dp (n, -1);
    
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] == -1) {
            continue;
        }
        
        int next = min(i + a[i], n - 1);
        for(int j = i + 1; j <= next; j++) {
            if(dp[j] != -1) {
                continue;
            }
            dp[j] = dp[i] + 1;
        }
    }
    return dp[n - 1];
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