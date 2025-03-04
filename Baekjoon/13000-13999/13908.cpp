#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int NUM = 9;
int answer = 0;
int cnt[NUM+1]; // cnt[i] : i가 사용된 횟수
bool must[NUM+1]; // 반드시 포함되어야 하는 숫자

void backtracking(int idx, int n, int check, int m) {
    if(idx == n) { // n자리 password 완성
        if(check == m) { // m개의 수를 모두 포함한 경우
            answer++;
        }
        return;
    }

    for(int i = 0; i <= NUM; i++) { // i : 비밀번호의 숫자
        if(++cnt[i] == 1 && must[i]) {
            check++;
        }
        backtracking(idx+1, n, check, m);
        if(--cnt[i] == 0 && must[i]) {
            check--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, num;

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> num;
        must[num] = true;
    }

    backtracking(0, n, 0, m);
    cout << answer;
    return 0;
}