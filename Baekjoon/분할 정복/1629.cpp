#include <iostream>

using namespace std;

typedef long long ll;

ll divide(int a, int b, int c) {
    if(b == 1) return a % c; // conquer

    // divide & combine
    // 1. b가 짝수일 때
    if(b % 2 == 0) {
        ll sub = divide(a, b/2, c);
        return (sub * sub) % c;
    }
    // 2. b가 홀수일 때
    return (a * divide(a, b-1, c)) % c;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << divide(a, b, c);
    return 0;
}