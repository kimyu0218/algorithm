#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<pi> tp) {
  int n = tp.size();
  vector<int> dp(n + 1, 0);

  for(int i = 0; i < n; i++) {
    int t = tp[i].first;
    int p = tp[i].second;
    int nt = i + t;

    if(nt > n) {
      continue;
    }
    int np = dp[i] + p;
    for(int j = nt; j <= n; j++) {
      dp[j] = max(dp[j], np);
    }
  }
  return dp[n];
}

int main() {
  int n;
  vector<pi> tp;

  cin >> n;

  tp.assign(n, {0, 0});
  for(int i = 0; i < n; i++) {
    cin >> tp[i].first >> tp[i].second;
  }

  cout << solution(tp);
  return 0;
}