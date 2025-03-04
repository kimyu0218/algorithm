#include <iostream>

using namespace std;

int cntDiff(int n, int rev) {
    int cnt = 0;
    for(int i = 0; i < 32; i++) {
        if((n & 1) != (rev & 1)) {
            cnt++;
        }
        n = n >> 1;
        rev = rev >> 1;
    }
    return cnt;
}

int main() {
    int n;

    cin >> n;
    cout << cntDiff(n, ~n+1);
    return 0;
}