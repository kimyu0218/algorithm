#include <iostream>

using namespace std;

const int MAX = 11;

int answer[MAX + 1];

void bruteforce(int sum, int n) {
  if(sum > n) {
    return;
  }
  if(sum == n) {
    answer[n]++;
    return;
  }

  for(int i = 1; i <= 3; i++) {
    bruteforce(sum + i, n);
  }
}
a
void solution() {
  for(int i = 1; i <= MAX; i++) {
    bruteforce(0, i);
  }
}

int main() {
  int t, n;

  cin >> t;

  solution();

  while(t--) {
    cin >> n;

    cout << answer[n] << '\n';
  }
  return 0;
}