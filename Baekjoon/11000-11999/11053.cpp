#include <iostream>

using namespace std;

const int MAX = 1000;
int a[MAX+1], dp[MAX+1];

int lis(int n) { // LIS 구하기
    for(int i = 1; i <= n; i++) {
        dp[i] = 1; // 초기값 1로 세팅
        for(int j = i-1; j > 0; j--) { // (i 이전 수열 검사)
            // 증가 수열 && 가장 긴 수열 길이
            if(a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    // 최대 길이 계산
    int length = 0;
    for(int i = 1; i <= n; i++) {
        if(dp[i] > length) length = dp[i];
    }
    return length;
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) // 수열 입력
        cin >> a[i];

    cout << lis(n);
    return 0;
}