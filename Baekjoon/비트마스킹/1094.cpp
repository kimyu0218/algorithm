#include <iostream>

using namespace std;

int cntStick(int x) { // 절반으로 자른 막대를 합친다 == 이진수의 개수
    int cnt = 0;
    while(x > 0) {
        if(x % 2) {
            cnt++;
        }
        x /= 2;
    }
    return cnt;
}

int main() {
    int x;

    cin >> x;
    cout << cntStick(x);
    return 0;
}