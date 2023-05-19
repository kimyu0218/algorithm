#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int knapsack(int n, int m, vector<pi> &item) {
    vector<int> dp(n+1, 0);
    for(int i = 0; i < m; i++) {
        int s = item[i].first; // 무게
        int p = item[i].second; // 가격
        for(int j = n; j >= s; j--) {
            dp[j] = max(dp[j], dp[j-s] + p);
        }
    }
    return dp[n];
}

int main() {
    int t, n, m;
    vector<pi> item; // (first : 크기, second : 가격)

    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> m;
        item.assign(m, {0, 0});
        for(int j = 0; j < m; j++) {
            cin >> item[j].first >> item[j].second;
        }
        cout << '#' << i << ' ' << knapsack(n, m, item) << '\n';
    }
    return 0;
}