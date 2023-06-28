#include <iostream>

using namespace std;

int solution(int n, int k) {
    if(n <= k) {
        return 0;
    }
    // 초기의 n개의 물병에 1L가 들어있으므로 물의 양은 nL
    int buy = 0; // 1L 물병을 구매하는 횟수
    while(true) {
        int cnt = 0, water = n;
        // 5 = 101 -> 4L짜리 물병 1개와 1L짜리 물병 1개
        while(water) {
            if(water & 1) {
                cnt++;
            }
            water >>= 1;
        }
        if(cnt <= k) {
            break;
        }
        n++; buy++;
    }
    return buy;
}

int main() {
    int n, k;

    cin >> n >> k;
    cout << solution(n, k);
    return 0;
}