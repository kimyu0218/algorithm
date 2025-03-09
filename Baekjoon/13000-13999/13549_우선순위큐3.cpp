#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int MAX = 1e5;

vector<int> sec;

struct info {
  int x, s;
};

struct cmp {
  bool operator() (info &i1, info &i2) {
    if(i1.s != i2.s) {
      return i1.s > i2.s;
    }
    return i1.x > i2.x;
  }
};

bool can_move(int x) {
  return x >= 0 && x <= MAX && sec[x] == MAX;
}

int bfs(int n, int k) {
  priority_queue<info, vector<info>, cmp> pq;

  sec.assign(MAX + 1, MAX);
  pq.push({n, 0});

  while(!pq.empty()) {
    int x = pq.top().x;
    int s = pq.top().s;
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