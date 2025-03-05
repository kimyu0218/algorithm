#include <iostream>

using namespace std;

const int SIZE = 8;

bool visited[SIZE + 1];
int arr[SIZE];

void backtracking(int idx, int m, int n) {
  if(idx == m) {
    for(int i = 0; i < m; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = 1; i <= n; i++) {
    if(visited[i]) {
      continue;
    }
    visited[i] = true;
    arr[idx] = i;
    backtracking(idx + 1, m, n);
    visited[i] = false;
  }
}

void solution(int n, int m) {
  backtracking(0, m, n);
}

int main() {
  int n, m;

  cin >> n >> m;

  solution(n, m);
  return 0;
}