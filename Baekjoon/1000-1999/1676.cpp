#include <iostream>
#include <vector>

using namespace std;

int cnt_denominator(int n, int d) {
    int cnt = 0;
    while(n % d == 0) {
        cnt++;
        n /= d;
    }
    return cnt;
}

int solution(int n) {
    int two_cnt = 0;
    int five_cnt = 0;

    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            two_cnt += cnt_denominator(i, 2);
        }
        if(i % 5 == 0) {
            five_cnt += cnt_denominator(i, 5);
        }
    }
    return min(two_cnt, five_cnt);
}

int main() {
    int n;

    cin >> n;

    cout << solution(n);
    return 0;
}