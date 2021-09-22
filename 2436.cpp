#include <iostream>
#include <cmath>

using namespace std;

int gcdRecursion(int a, int b) { // 최대 공약수 구하기
    if(b == 0) return a;
    return gcdRecursion(b, a%b);
}

string naturalNumberPair(int gcd, int lcm) { // 두 자연수 찾기
    int multi = lcm / gcd, a = gcd, b = gcd;

    for(int i = sqrt(multi); i >= 1; i--) {
        // 1. i는 multi의 약수
        // 2. i와 multi/is는 서로소
        if(multi % i == 0 && gcdRecursion(i, multi/i) == 1) {
            a *= i; b *= multi/i;
            break;
        }
    }
    return to_string(a) + ' ' + to_string(b);
}

int main() {
    int gcd, lcm, multi, a, b;
    cin >> gcd >> lcm;
    cout << naturalNumberPair(gcd, lcm); // 두 자연수 출력하기
    return 0;
}