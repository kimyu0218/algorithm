#include <iostream>
#include <vector>

using namespace std;

int min_cnt(int cost, int n, vector<int> coin) {
    int cnt = 0; // 동전 개수 저장하는 변수
    for(int i = n-1; i >= 0; i--) {
        if(coin[i] > cost) continue; // 나눌 수 없는 경우 pass
        cnt += (cost / coin[i]);
        cost %= coin[i]; // 잔액 계산
    }
    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coin(n, 0);
    for(int i = 0; i < n; i++) // 동전 금액 입력
        cin >> coin[i];
    cout << min_cnt(k, n, coin);
    return 0;
}