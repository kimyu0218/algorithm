#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

void hanoi(int n, int src, int dst, int bypass) {
    if(n <= 0) {
        return;
    }
    hanoi(n - 1, src, bypass, dst);
    cout << src << ' ' << dst << '\n';
    hanoi(n - 1, bypass, dst, src);
}

void solution(int n) {
    ll k = pow(2, n) - 1;

    cout << k << '\n';
    hanoi(n, 1, 3, 2);
}

int main() {
    int n;

    cin >> n;

    solution(n);
    return 0;
}