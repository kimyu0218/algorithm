#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int solution(int n, int k, vector<pi> items) {
    vector<int> dp(k + 1, 0);

    for(int i = 0; i < n; i++) {
        int w = items[i].first;
        int v = items[i].second;

        if(w > k) {
            continue;
        }
        for(int j = k; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    return dp[k];
}

int main() {
    int n, k;
    vector<pi> items;

    cin >> n >> k;

    items.assign(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    cout << solution(n, k, items);
    return 0;
}