#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 8;
int arr[SIZE]; // n자리의 자릿수 저장

bool isPrime(int n) { // 소수 여부 리턴
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

bool checkPrime(int cnt) { // cnt자리의 숫자가 소수인가
    int answer = 0;
    for(int i = 0; i <= cnt; i++) {
        answer = answer * 10 + arr[i];
    }
    return isPrime(answer);
}

void backtracking(int cnt, int n) {
    if(cnt == n) { // 기저 조건
        for(int i = 0; i < n; i++) {
            cout << arr[i];
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= 9; i++) {
        arr[cnt] = i;
        if(checkPrime(cnt)) { // 신기한 소수를 만족하는 경우
            backtracking(cnt+1, n);
        }
    }
}

int main() {
    int n;
    int prime[4] = {2, 3, 5, 7};

    cin >> n;

    for(int i = 0; i < 4; i++) {
        arr[0] = prime[i];
        backtracking(1, n);
    }
    return 0;
}