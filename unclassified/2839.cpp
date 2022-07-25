#include <iostream>

using namespace std;

int computeMin(int n) { // 최소 봉지수 계산하기
    for(int i = (int) n/5; i >= 0; i--) { // (i : 5kg 봉지수)
        int tmp = n - 5*i; // 남은 킬로그램
        if(tmp%3 == 0)
            return i + (int) tmp/3; // 최소 봉지수 반환
    }
    return -1; // 정확하게 N 킬로그램 배달하지 못하는 경우
}

int main() {
    int n;
    cin >> n;

    cout << computeMin(n);
    return 0;
}