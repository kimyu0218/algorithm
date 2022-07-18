#include <iostream>

using namespace std;

int digit_sum(int n) { // 자릿수 합 구하기
    int digit = 1000000, sum = 0;
    while(n) {
        sum += n / digit;
        n %= digit; digit /= 10;
    }
    return sum;
}

int find_constructor(int n) { // 생성자 찾기
    for(int i = 1; i <= n; i++) {
        // i가 n의 생성자인 경우 (n이 i의 분해합인 경우)
        if(digit_sum(i) + i == n)
            return i;
    }
    return 0; // 생성자가 없는 경우
}

int main() {
    int n;
    cin >> n;

    cout << find_constructor(n);
    return 0;
}