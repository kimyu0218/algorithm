#include <iostream>

using namespace std;

typedef long long ll;

ll combination(int n, int m) { // 조합
    if(n == 0) return 1;

    ll a = 1, b = 1;
    for(int i = n; i >= 1; i--) {
        a *= m--;
        b *= i;
    }
    return a / b;
}

int main() {
    int t, n, m;
    cin >> t;

    while(t--) { // 테스트 케이스
        cin >> n >> m;
        cout << combination(min(n, m-n), m) << '\n';
    }
    return 0;
}