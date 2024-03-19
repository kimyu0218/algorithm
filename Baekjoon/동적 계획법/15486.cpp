#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<pi> schedule) {
    int n = schedule.size();
    vector<int> dp(n + 1, 0);

    int t = schedule[0].first;
    int p = schedule[0].second;
    if(t <= n) {
        dp[t] = p;
    }

    for(int i = 0; i < n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);

        int t = schedule[i].first;
        int p = schedule[i].second;
        int next = i + t;
        if(next > n) {
            continue;
        }
        dp[next] = max(dp[next], dp[i] + p);
    }
    return max(dp[n], dp[n - 1]);
}

int main() {
    int n;
    vector<pi> schedule;

    cin >> n;

    schedule.assign(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> schedule[i].first >> schedule[i].second;
    }

    cout << solution(schedule);
    return 0;
}