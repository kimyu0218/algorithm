#include <iostream>
#include <set>

using namespace std;

const int SIZE = 20;
const int MAX = 1e6 * 2;

set<int> sums;
int s[SIZE];

void backtracking(int cnt, int n, int start, int sum) {
    sums.insert(sum);

    for(int i = start; i < n; i++) {
        backtracking(cnt + 1, n, i + 1, sum + s[i]);
    }
}

int solution(int n) {
    backtracking(0, n, 0, 0);

    for(int i = 1; i <= MAX; i++) {
        if(sums.find(i) == sums.end()) {
            return i;
        }
    }
    return MAX + 1;
}

int main() {
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    cout << solution(n);
    return 0;
}