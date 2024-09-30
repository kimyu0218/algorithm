#include <iostream>

using namespace std;

typedef pair<int, int> pi;

const int N = 11;
const int OPERATOR = 4;
const int MAX = 1e9;
const int MIN = -MAX;

int max_result = MIN - 1;
int min_result = MAX + 1;

int a[N];
int operator_cnt[OPERATOR];

int calculate(int operator_idx, int a, int b) {
    if(operator_idx == 0) {
        return a + b;
    }
    if(operator_idx == 1) {
        return a - b;
    }
    if(operator_idx == 2) {
        return a * b;
    }
    return a / b;
}

void backtracking(int idx, int n, int result) {
    if(idx == n) {
        max_result = max(result, max_result);
        min_result = min(result, min_result);
        return;
    }
    
    for(int i = 0; i < OPERATOR; i++) {
        if(!operator_cnt[i]) {
            continue;
        }
        operator_cnt[i]--;
        int next_result = calculate(i, result, a[idx]);
        backtracking(idx + 1, n, next_result);
        operator_cnt[i]++;
    }
}

pi solution(int n) {
    backtracking(1, n, a[0]);
    return { max_result, min_result };
}

int main() {
    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < OPERATOR; i++) {
        cin >> operator_cnt[i];
    }
    
    pi result = solution(n);
    
    cout << result.first << '\n' << result.second;
    return 0;
}