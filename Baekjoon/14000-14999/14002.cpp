#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> get_lcs(int n, vector<int> a, int len, vector<int> dp) {
  stack<int> answer;

  for(int i = n - 1; i >= 0; i--) {
    if(dp[i] != len) {
      continue;
    }

    answer.push(a[i]);
    if(--len == 0) {
      break;
    }
  }
  return answer;
}

void solution(vector<int> a) {
  int answer = 1;
  int n = a.size();
  vector<int> dp(n, 1);

  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(a[i] > a[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    answer = max(answer, dp[i]);
  }

  cout << answer << '\n';
  stack<int> lcs = get_lcs(n, a, answer, dp);
  while(!lcs.empty()) {
    cout << lcs.top() << ' ';
    lcs.pop();
  }
}

int main() {
  int n;
  vector<int> a;

  cin >> n;

  a.assign(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  solution(a);
  return 0;
}