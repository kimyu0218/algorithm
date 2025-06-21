#include <string>
#include <vector>
#include <map>

using namespace std;

const int DAYS = 10;

map<string, int> make_item_map(int n, vector<string> want) {
    map<string, int> items;

    for(int i = 0; i < n; i++) {
        items[want[i]] = i + 1;
    }
    return items;
}

vector<vector<int>> make_dp(int m, int n, vector<string> discount, map<string, int> items) {
    vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i + 1][j] = dp[i][j];
        }

        int idx = items[discount[i]];
        if(idx) {
            dp[i + 1][idx]++;
        }
    }
    return dp;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int n = discount.size();
    int m = want.size();

    map<string, int> items = make_item_map(m, want);
    vector<vector<int>> dp = make_dp(items.size(), n, discount, items);

    for(int i = 1; i <= n + 1 - DAYS; i++) {
        bool flag = true;

        for(int j = 0; j < m; j++) {
            int idx = items[want[j]];
            int cnt = dp[i + DAYS - 1][idx] - dp[i - 1][idx];

            if(cnt != number[j]) {
                flag = false;
                break;
            }
        }
        answer += flag;
    }
    return answer;
}