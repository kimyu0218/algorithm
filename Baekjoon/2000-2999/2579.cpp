#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stairs) {
    if(n == 1) {
        return stairs[0];
    }
    if(n == 2) {
        return stairs[0] + stairs[1];
    }

    vector<int> dp(n, 0);
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    for(int i = 3; i < n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i];
    }
    return dp[n - 1];
}

int main() {
    int n;
    vector<int> stairs;

    cin >> n;

    stairs.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> stairs[i];
    }

    cout << solution(n, stairs);
    return 0;
}