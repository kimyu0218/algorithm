#include <iostream>

using namespace std;

int fact(int num) { // 팩토리얼 함수
    if(num == 0 || num == 1) return 1;

    int result = 1;
    for(int i = 1; i <= num; i++) result *= i;
    return result;
}
// 이항 계수 구하기
int binaryCoef(int n, int k) { return fact(n) / (fact(k) * fact(n-k)); }

int main() {
    int n, k;
    cin >> n >> k;

    cout << binaryCoef(n, k);
    return 0;
}