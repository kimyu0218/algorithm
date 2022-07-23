#include <iostream>

using namespace std;

// 피보나치 점화식 : f(n) = f(n-1) + f(n-2)
int fibo(int n) {
    if(n == 0 || n == 1) return n;
    return fibo(n-1) + fibo(n-2);
}

int main() {
    int n;
    cin >> n;

    cout << fibo(n);
    return 0;
}