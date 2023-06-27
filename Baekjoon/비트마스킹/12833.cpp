#include <iostream>

using namespace std;

int xorOperation(int a, int b, int c) {
    if(c % 2) { // c가 홀수인 경우
        return a ^ b;
    }
    return a; // c가 짝수인 경우
}

int main() {
    int a, b, c;

    cin >> a >> b >> c;
    cout << xorOperation(a, b, c);
    return 0;
}