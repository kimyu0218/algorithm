#include <iostream>

using namespace std;

const int MAX = 50;
const int N = 20;
const int ROMAM_NUM = 4;

int result = 0;

bool visited[MAX * N + 1];
int roman_nums[ROMAM_NUM] = { 1, 5, 10, 50 };

void backtracking(int cnt, int n, int idx, int sum) {
    if(cnt == n) {
        if(!visited[sum]) {
            result++;
            visited[sum] = true;
        }
        return;
    }
    
    for(int i = idx; i < ROMAM_NUM; i++) {
        backtracking(cnt + 1, n, i, sum + roman_nums[i]);
    }
}

int solution(int n) {
    backtracking(0, n, 0, 0);
    
    return result;
}

int main() {
    int n;
    
    cin >> n;

    cout << solution(n);
    return 0;
}