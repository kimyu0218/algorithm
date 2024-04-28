#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int solution(int n) {
    int answer = 0;
    if(n == 1) {
        return 1;
    }

    vector<int> dp (n, 0);
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i < n; i++) {
        dp[i] = (dp[i - 2] + dp [i - 1]) % MOD;
    }
    return dp[n - 1];
}