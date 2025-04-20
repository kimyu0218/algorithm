#include <iostream>

using namespace std;

int answer = 0;

void backtracking(int pre, int curr, int sum) {
    if(sum <= 0) {
        answer += (sum == 0);
        return;
    }

    if(curr > sum) {
        return;
    }
    if(pre == 0) {
        backtracking(curr, curr + 1, sum - curr);
        backtracking(pre, curr + 1, sum);
    }
    else if(pre == curr - 1) {
        backtracking(curr, curr + 1, sum - curr);
    }
}

void solution(int n) {
    backtracking(0, 1, n);
}

int main() {
    int n;

    cin >> n;

    solution(n);

    cout << answer;
    return 0;
}