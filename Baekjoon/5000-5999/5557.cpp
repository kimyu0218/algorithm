#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 20;

bool check_range(int num) {
    return num >= 0 && num <= MAX;
}

ll solution(vector<int> num) {
    int n = num.size();
    vector<vector<ll>> dp (n - 1, vector<ll> (MAX + 1, 0));

    dp[0][num[0]] = 1;

    for(int i = 1; i < n - 1; i++) {
        for(int j = 0; j <= MAX; j++) {
            if(!dp[i - 1][j]) {
                continue;
            }

            int sum1 = j + num[i];
            if(check_range(sum1)) {
                dp[i][sum1] += dp[i - 1][j];
            }
            int sum2 = j - num[i];
            if(check_range(sum2)) {
                dp[i][sum2] += dp[i - 1][j];
            }
        }
    }
    return dp[n - 2][num[n - 1]];
}

int main() {
    int n;
    vector<int> num;

    cin >> n;

    num.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << solution(num);
    return 0;
}