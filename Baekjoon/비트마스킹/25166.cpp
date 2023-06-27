#include <iostream>

using namespace std;
const int CNT = 10; // 아리가 가진 동전 종류

string solution(int s, int m) {
    if(s <= 1023) { // s가 1023 이하인 경우, 아리의 돈으로 살 수 있음
        return "No thanks";
    }
    s -= 1023; // 아리가 살 수 있는 금액 빼기
    for(int i = 0; i <= CNT; i++) {
        bool f1 = s & (1 << i);
        bool f2 = m & (1 << i);
        if(f1 && !f2) {
            return "Impossible";
        }
    }
    return "Thanks";
}

int main() {
    int s, m;

    cin >> s >> m;
    cout << solution(s, m);
    return 0;
}