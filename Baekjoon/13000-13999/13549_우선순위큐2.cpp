#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int MAX = 1e5;

vector<int> sec;

struct cmp {
  bool operator() (pi &p1, pi &p2) {
    if(p1.second != p2.second) {
      return p1.second > p2.second;
    }
    return p1.first > p2.first;
  }
};

bool can_move(int x) {
  return x >= 0 && x <= MAX && sec[x] == MAX;
}

int bfs(int n, int k) {
  priority_queue<pi, vector<pi>, cmp> pq;

  sec.assign(MAX + 1, MAX);
  pq.push({n, 0});

  while(!pq.empty()) {
    int x = pq.top().first;
    int s = pq.top().second;
    pq.pop();

    if(x == k) {
      break;
    }

    if(can_move(2 * x)) {
      sec[2 * x] = s;
      pq.push({2 * x, sec[2 * x]});
    }
    if(can_move(x - 1)) {
      sec[x - 1] = s + 1;
      pq.push({x - 1, sec[x - 1]});
    }
    if(can_move(x + 1)) {
      sec[x + 1] = s + 1;
      pq.push({x + 1, sec[x + 1]});
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