#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
  int answer = 0;

  int max_digit = to_string(n).length();
  for(int i = 1; i < max_digit; i++) {
    int cnt = pow(10, i) - pow(10, i - 1);
    answer += cnt * i;
  }

  int cnt = (n + 1) - pow(10, max_digit - 1);
  return answer + cnt * max_digit;
}

int main() {
  int n;

  cin >> n;

  cout << solution(n);
  return 0;
}