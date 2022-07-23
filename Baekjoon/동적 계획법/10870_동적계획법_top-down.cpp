#include <iostream>

using namespace std;

const int MAX = 20;
int dp[MAX+1];

// 피보나치 점화식 : f(n) = f(n-1) + f(n-2)
int fibo(int n) {
    if(n == 0 || n == 1) return n;
    if(dp[n]) return dp[n]; // 이전에 계산한 값이 존재하는 경우
    return dp[n] = fibo(n-1) + fibo(n-2);
}

int main() {
    int n;
    cin >> n;

    cout << fibo(n);
    return 0;
}