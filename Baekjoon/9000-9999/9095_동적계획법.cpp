#include <iostream>

using namespace std;

const int MAX = 11;

int dp[MAX + 1];

void solution() {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for(int i = 4; i <= MAX; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }
}

int main() {
  int t, n;

  cin >> t;

  solution();

  while(t--) {
    cin >> n;

    cout << dp[n] << '\n';
  }
  return 0;
}