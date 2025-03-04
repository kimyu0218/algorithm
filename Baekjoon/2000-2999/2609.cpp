#include <iostream>

using namespace std;

int gcd(int a, int b){ // 최대 공약수
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b, int g) { // 최소 공배수
    return (a * b) / g;
}

int main() {
    int a, b;
    cin >> a >> b;
    int g = gcd(max(a, b), min(a, b));
    cout << g << '\n';
    cout << lcm(a, b, g);
    return 0;
}