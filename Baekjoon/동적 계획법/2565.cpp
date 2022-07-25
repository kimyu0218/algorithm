#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;
vector<pair<int, int>> pole;

int lis(int n) { // LIS 구하기
    for(int i = 1; i <= n; i++) {
        dp[i] = 1; // 초기값 1로 세팅
        for(int j = 0; j < i; j++) {
            if(pole[i].second > pole[j].second) // 증가 수열인 경우
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int length = 0;
    for(int i = 1; i <= n; i++) {
        if(dp[i] > length) length = dp[i];
    }
    return n - length;
}

int main() {
    int n, start, end;
    cin >> n;

    dp.assign(n+1, 0);
    pole.assign(n+1, {0, 0});
    for(int i = 1; i <= n; i++)
        cin >> pole[i].first >> pole[i].second;
    sort(pole.begin(), pole.end());

    cout << lis(n);
    return 0;
}