#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

const int COLOR = 3;
const int INF = 1e6 + 1;

int min_cost(int color, vector<vector<int>> houses) {
    int result = INF;
    int n = houses.size();
    vector<vector<int>> dp(n, vector<int> (COLOR, 0));

    for(int i = 0; i < COLOR; i++) {
        dp[0][i] = (i == color) ? houses[0][i] : INF;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < COLOR; j++) {
            int diff_color1 = (j + 1 + COLOR) % COLOR;
            int diff_color2 = (j + 2 + COLOR) % COLOR;
            dp[i][j] = min(dp[i - 1][diff_color1], dp[i - 1][diff_color2]) + houses[i][j];
        }
    }

    for(int i = 0; i < COLOR; i++) {
        if(i == color) {
            continue;
        }
        result = min(result, dp[n - 1][i]);
    }
    return result;
}

int solution(vector<vector<int>> houses) {
    int result = INF;

    for(int i = 0; i < COLOR; i++) {
        result = min(result, min_cost(i, houses));
    }
    return result;
}

int main() {
    int n;
    vector<vector<int>> houses;

    cin >> n;

    houses.assign(n, vector<int> (COLOR, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < COLOR; j++) {
            cin >> houses[i][j];
        }
    }

    cout << solution(houses);
    return 0;
}