#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

vector<int> makeOne(int n) {
    vector<pi> dp(n+1); // (first : 연산 횟수, second : 연산 결과)
    vector<int> result; // 연산 순서 저장

    dp[1] = {0, 0};
    for(int i = 2; i <= n; i++) {
        // case 3
        dp[i] = {dp[i-1].first+1, i-1};

        // case 2 : 2로 나누어 떨어질 때
        if(i % 2 == 0 && dp[i/2].first < dp[i].first) {
            dp[i] = {dp[i/2].first+1, i/2};
        }

        // case 1 : 3으로 나누어 떨어질 때
        if(i % 3 == 0 && dp[i/3].first < dp[i].first) {
            dp[i] = {dp[i/3].first+1, i/3};
        }
    }

    // 연산 순서 만들기
    int x = n;
    while(x != 0) {
        result.push_back(x);
        x = dp[x].second;
    }
    return result;
}

int main() {
    int n; // 정수

    // 입력
    cin >> n;

    // 연산
    vector<int> result = makeOne(n);

    // 출력
    cout << result.size()-1 << '\n';
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}