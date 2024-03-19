#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<pi> ab) {
    int n = ab.size();
    vector<int> dp(n + 1, 1);

    sort(ab.begin(), ab.end());

    for(int i = 1; i < n; i++) {
        int b = ab[i].second;

        for(int j = 0; j < i; j++) {
            if(b > ab[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        dp[n] = max(dp[n], dp[i]);
    }
    return n - dp[n];
}

int main() {
    int n;
    vector<pi> ab;

    cin >> n;

    ab.assign(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> ab[i].first >> ab[i].second;
    }

    cout << solution(ab);
    return 0;
}