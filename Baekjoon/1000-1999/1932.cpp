#include <iostream>

using namespace std;

const int MAX = 500;
int triangle[MAX+1][MAX+1];
long long dp[MAX+1][MAX+1];

void compute (int n) { // 정수 삼각형 계산
    dp[1][1] = triangle[1][1];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
    }
}

long long max_triangle(int n) { // 최대 합 계산
    long long max = 0;
    for(int i = 1; i <= n; i++) {
        if(dp[n][i] > max) max = dp[n][i];
    }
    return max;
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) { // 정수 삼각형 입력
        for(int j = 1; j <= i; j++)
            cin >> triangle[i][j];
    }

    compute(n);
    cout << max_triangle(n);
    return 0;
}