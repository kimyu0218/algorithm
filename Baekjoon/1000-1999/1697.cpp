#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int MAX = 1e5;

vector<int> sec;

bool can_move(int x) {
  return x >= 0 && x <= MAX && sec[x] == MAX;
}

vector<int> get_next_position(int x) {
  vector<int> pos;
  if(can_move(x - 1)) {
    pos.push_back(x - 1);
  }
  if(can_move(x + 1)) {
    pos.push_back(x + 1);
  }
  if(can_move(2 * x)) {
    pos.push_back(2 * x);
  }
  return pos;
}

int bfs(int n, int k) {
  queue<pi> q;

  sec.assign(MAX + 1, MAX);
  q.push({n, 0});

  while(!q.empty()) {
    int x = q.front().first;
    int s = q.front().second;
    int next_s = s + 1;
    q.pop();

    if(x == k) {
      break;
    }

    vector<int> next_pos = get_next_position(x);
    for(int j = 0; j < next_pos.size(); j++) {
      int next = next_pos[j];
      sec[next] = next_s;
      q.push({next, next_s});
    }
  }
  return sec[k];
}

int solution(int n, int k) {
  if(n == k) {
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