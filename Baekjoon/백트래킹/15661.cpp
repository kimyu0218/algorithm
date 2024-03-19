#include <iostream>

using namespace std;

const int MAX = 20;

int result = MAX * 100;
bool is_start[MAX];
int s[MAX][MAX];

int compute_diff(int n) {
    int start = 0;
    int link = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(is_start[i] != is_start[j]) {
                continue;
            }
            if(is_start[i]) {
                start += s[i][j] + s[j][i];
            }
            else {
                link += s[i][j] + s[j][i];
            }
        }
    }
    return abs(start - link);
}

void solution(int idx, int n) {
    if(idx == n) {
        result = min(result, compute_diff(n));
        return;
    }

    for(int i = idx; i < n; i++) {
        is_start[i] = true;
        solution(i + 1, n);
        is_start[i] = false;
    }

}

int main() {
    int n;

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    solution(0, n);

    cout << result;
    return 0;
}