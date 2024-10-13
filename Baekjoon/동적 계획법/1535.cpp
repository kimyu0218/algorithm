#include <iostream>
#include <vector>

using namespace std;

const int MAX_HP = 100;

int solution(vector<int> l, vector<int> j) {
    int n = l.size();
    vector<int> dp (MAX_HP + 1, 0);
    
    for(int i = 0; i < n; i++) {
        for(int k = MAX_HP; k >= l[i] + 1; k--) {
            dp[k] = max(dp[k], dp[k - l[i]] + j[i]);
            dp[0] = max(dp[0], dp[k]);
        }
    }
    return dp[0];
}

int main() {
    int n;
    vector<int> l, j;
    
    cin >> n;
    
    l.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }
    j.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> j[i];
    }
    
    cout << solution(l, j);
    return 0;
}