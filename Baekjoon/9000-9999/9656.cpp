#include <iostream>
#include <vector>

using namespace std;

string rockGame(int n) {
    if(n == 1 || n == 3) { // SK이 가져감 == CY의 승
        return "CY";
    }
    if(n == 2 || n == 4) { // CY이 가져감 == SK의 승
        return "SK";
    }

    vector<char> dp (n+1, '\0'); // dp[i] : i번째 돌을 가져가는 사람
    dp[1] = dp[3] = 'S';
    dp[2] = dp[4] = 'C';
    for(int i = 5; i <= n; i++) {
        dp[i] = dp[i-4];
    }

    if(dp[n] == 'C') { // n번째 돌을 CY이 가져감 == SK의 승
        return "SK";
    }
    return "CY"; // n번째 돌을 SK이 가져감 == CY의 승
}

int main() {
    int n;
    cin >> n;

    cout << rockGame(n);
    return 0;
}