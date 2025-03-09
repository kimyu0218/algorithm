#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int MAX = 1e5;

int cnt[MAX];
vector<int> sec;

bool can_move(int x, int s) {
  return x >= 0 && x <= MAX && sec[x] >= s;
}

vector<int> get_next_position(int x, int s) {
  vector<int> pos;
  if(can_move(x - 1, s)) {
    pos.push_back(x - 1);
  }
  if(can_move(x + 1, s)) {
    pos.push_back(x + 1);
  }
  if(can_move(2 * x, s)) {
    pos.push_back(2 * x);
  }
  return pos;
}

pi bfs(int n, int k) {
  queue<pi> q;

  sec.assign(MAX + 1, MAX);
  cnt[n] = 1;
  q.push({n, 0});

  while(!q.empty()) {
    int x = q.front().first;
    int s = q.front().second;
    int next_s = s + 1;
    q.pop();

    if(x == k) {
      break;
    }

    vector<int> next_pos = get_next_position(x, next_s);
    for(int j = 0; j < next_pos.size(); j++) {
      int next = next_pos[j];
      sec[next] = next_s;
      cnt[next]++;
      q.push({next, next_s});
    }
  }
  return { sec[k], cnt[k] };
}

pi solution(int n, int k) {
  if(n == k) {
    return { 0, 1 };
  }
  return bfs(n, k);
}

int main() {
  int n, k;

  cin >> n >> k;

  pi answer = solution(n, k);

  cout << answer.first << '\n' << answer.second;
  return 0;
}