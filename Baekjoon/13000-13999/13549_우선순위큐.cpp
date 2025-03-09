#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int MAX = 1e5;

vector<int> sec;

bool can_move(int x) {
  return x >= 0 && x <= MAX && sec[x] == MAX;
}

int bfs(int n, int k) {
  priority_queue<pi, vector<pi>, greater<>> pq;

  sec.assign(MAX + 1, MAX);
  pq.push({0, n});

  while(!pq.empty()) {
    int s = pq.top().first;
    int x = pq.top().second;
    pq.pop();

    if(x == k) {
      break;
    }

    if(can_move(2 * x)) {
      sec[2 * x] = s;
      pq.push({s, sec[2 * x]});
    }
    if(can_move(x - 1)) {
      sec[x - 1] = s + 1;
      pq.push({sec[x - 1], x - 1});
    }
    if(can_move(x + 1)) {
      sec[x + 1] = s + 1;
      pq.push({sec[x + 1], x + 1});
    }
  }
  return sec[k];
}

int solution(int n, int k) {
  if(n == k || 2 * n == k) {
    return 0;
  }
  return bfs(n, k);
}

int main() {
  int n, k;

  cin >> n >> k;

  cout << solution(n, k);
  return 0;
}