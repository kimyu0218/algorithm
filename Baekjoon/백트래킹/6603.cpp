#include <iostream>

using namespace std;

const int N = 6;
const int SIZE = 13;

int selected[N];
int s[SIZE];

void backtracking(int idx, int start, int k) {
    if(idx == N) {
        for(int i = 0; i < N; i++) {
            cout << selected[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = start; i < k; i++) {
        selected[idx] = s[i];
        backtracking(idx + 1, i + 1, k);
    }
}

void solution(int k) {
    backtracking(0, 0, k);
    cout << '\n';
}

int main() {
    int k;

    while(true) {
        cin >> k;

        if(!k) {
            break;
        }

        for(int i = 0; i < k; i++) {
            cin >> s[i];
        }

        solution(k);
    }
    return 0;
}