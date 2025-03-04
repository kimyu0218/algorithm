#include <iostream>

using namespace std;

const int E = 15;
const int S = 28;
const int M = 19;

int compute_year(int year, int max) {
  int mod = year % max;
  return mod ? mod : max;
}

int solution(int e, int s, int m) {
  int answer = 1;
  
  while(true) {
    int tmp_e = compute_year(answer, E);
    int tmp_s = compute_year(answer, S);
    int tmp_m = compute_year(answer, M);
    
    if (tmp_e == e && tmp_s == s && tmp_m == m) {
      return answer;
    }
    answer++;
  }
}

int main() {
  int e, s, m;
  
  cin >> e >> s >> m;
  
  cout << solution(e, s, m);
  return 0;
}
