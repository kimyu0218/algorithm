#include <iostream>

using namespace std;

int c(int a, int b) {
    return a ^ b;
}

int main() {
    int a, b;

    cin >> a >> b;
    cout << c(a, b);
    return 0;
}