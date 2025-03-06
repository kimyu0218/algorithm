#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll solution(int n) {
  ll answer = 0;
  if(n <= 2) {
    return 1;
  }

  vector<vector<ll>> dp(n + 2, vector<ll> (2, 0));
  dp[1][1] = 1;
  dp[2][0] = 1;

  for(int i = 3; i <= n; i++) {
    dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] += dp[i - 1][0];
    answer = max(answer, dp[i][0] + dp[i][1]);
  }
  return answer;
}

int main() {
  int n;

  cin >> n;

  cout << solution(n);
  return 0;
}