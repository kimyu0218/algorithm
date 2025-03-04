#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 1e4 * 5 + 1;

int solution(int n) {
    vector<int> dp (n + 1, INF);
    
    for(int i = 1; i <= n; i++) {
        int square = sqrt(i);
        if(i == pow(square, 2)) {
            dp[i] = 1;
            continue;
        }
        for(int j = 1; j <= i / 2; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }
    return dp[n];
}

int main() {
    int n;
    
    cin >> n;
    
    cout << solution(n);
    return 0;
}