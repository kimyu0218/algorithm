#include <iostream>
#include <vector>

using namespace std;

int expensiveCardPack(int n, vector<int> &p) {
    vector<int> dp (n+1, 0); // dp[i]: 카드 i개를 가장 비싸게 구매한 금액
    for(int i = 1; i <= n; i++) {
        dp[i] = p[i];
        for(int j = 0; j <= i; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
        }
    }
    return dp[n]; // 카드 n개를 가장 비싸게 구매한 금액
}

int main() {
    int n; // 카드 개수
    vector<int> p; // p[i] : i개의 카드가 든, 카드팩 가격

    cin >> n;
    p.assign(n+1, 0);
    for(int i = 1; i <= n; i++) { // 카드팩 가격 입력
        cin >> p[i];
    }
    cout << expensiveCardPack(n, p);
    return 0;
}