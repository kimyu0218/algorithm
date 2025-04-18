#include <iostream>

using namespace std;

const int N = 10;

bool stop = false;

bool visited[N];
int input[N];
int cnt_bigger[N];
int answer[N];

bool is_correct_order(int num) {
    return (cnt_bigger[num] == input[num]);
}

void count_bigger_num(int idx, int num) {
    cnt_bigger[num] = 0;
    for(int i = idx - 1; i >= 0; i--) {
        cnt_bigger[num] += (answer[i] > num);
    }
}

void backtracking(int idx, int n) {
    if(idx == n) {
        stop = true;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(stop) {
            return;
        }
        if(visited[i]) {
            continue;
        }

        visited[i] = true;

        answer[idx] = i;
        count_bigger_num(idx, i);
        if(is_correct_order(i)) {
            backtracking(idx + 1, n);
        }

        visited[i] = false;
    }
}

void solution(int n) {
    backtracking(0, n);

    for(int i = 0; i < n; i++) {
        cout << answer[i] + 1 << ' ';
    }
}

int main() {
    int n;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    solution(n);
    return 0;
}