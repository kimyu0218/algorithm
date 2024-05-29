#include <iostream>

using namespace std;

const int SIZE = 8;

int answer = 0;
bool visited[SIZE];
int num[SIZE];
int a[SIZE];

void backtracking(int idx, int n) {
    if(idx == n) {
        int sum = 0;
        for(int i = 0; i < n - 1; i++) {
            sum += abs(a[i] - a[i + 1]);
        }
        answer = max(answer, sum);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i]) {
            continue;
        }
        visited[i] = true;
        a[idx] = num[i];
        backtracking(idx + 1, n);
        visited[i] = false;
    }
}

int solution(int n) {
    backtracking(0, n);
    return answer;
}

int main() {
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << solution(n);
    return 0;
}