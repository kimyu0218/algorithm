#include <iostream>
#include <vector>

using namespace std;

int n, cnt;
vector<int> num;

void bruteforce(int idx, int sum, int s) {
    if(idx == n) { // 기저 조건
        if(sum == s) { // 부분집합의 합이 s인 경우
            cnt++;
        }
        return;
    }
    
    bruteforce(idx+1, sum, s); // idx 선택하지 않음
    bruteforce(idx+1, sum + num[idx], s); // idx 선택함
}

int main() {
    int s;

    cin >> n >> s;
    num.assign(n, 0);
    cnt = (s == 0) ? -1 : 0; // 공집합 제외 처리
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    bruteforce(0, 0, s);
    cout << cnt;
    return 0;
}