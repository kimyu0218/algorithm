#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;
const int INF = 1e4 + 1;

bool visited[SIZE];
int arr[SIZE];

vector<int> input (SIZE, INF);

void backtracking(int idx, int m, int start, int n) {
  if(idx == m) {
    for(int i = 0; i < m; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = start; i < n; i++) {
    if(visited[i]) {
      continue;
    }
    visited[i] = true;
    arr[idx] = input[i];
    backtracking(idx + 1, m, i + 1, n);
    visited[i] = false;
  }
}

void solution(int n, int m) {
  sort(input.begin(), input.end());
  backtracking(0, m, 0, n);
}

int main() {
  int n, m;

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> input[i];
  }

  solution(n, m);
  return 0;
}