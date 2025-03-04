#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll n, sum = 0, unit = 1;

    cin >> n;
    while(n > 0) {
        if(n & 1) {
            sum += unit;
        }
        unit *= 3;
        n = n >> 1;
    }
    cout << sum;
    return 0;
}