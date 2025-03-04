#include <iostream>
#include <vector>

using namespace std;

const int COLOR = 3;
const int INF = 1e6 + 1;

int solution(int n, vector<vector<int>> houses) {
    int result = INF;
    vector<vector<int>> dp(n + 1, vector<int> (3, 0));

    for(int i = 0; i < COLOR; i++) {
        dp[0][i] = houses[0][i];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < COLOR; j++) {
            int diff_color1 = (j + 1 + COLOR) % COLOR;
            int diff_color2 = (j + 2 + COLOR) % COLOR;
            dp[i][j] = min(dp[i - 1][diff_color1], dp[i - 1][diff_color2]) + houses[i][j];
        }
    }

    for(int i = 0; i < COLOR; i++) {
        result = min(result, dp[n - 1][i]);
    }
    return result;
}

int main() {
    int n;
    vector<vector<int>> houses;

    cin >> n;

    houses.assign(n, vector<int> (3, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < COLOR; j++) {
            cin >> houses[i][j];
        }
    }

    cout << solution(n, houses);
    return 0;
}