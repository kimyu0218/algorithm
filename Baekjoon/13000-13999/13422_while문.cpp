#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int cnt_steal(int n, int m, int k, vector<int> cost) {
    int cnt = 0; // 붙잡히지 않고 돈을 훔치는 방법 저장
    int left = 0, right = m-1;
    ll sum = 0;

    // 0부터 m-1번째 집에서 훔칠 수 있는 금액 합
    for(int i = 0; i < m; i++) sum += (ll) cost[i];
    if(n == m) return (sum < k); // 한 번에 모든 집 방문 가능한 경우 (더 이상 돌 필요없음)

    while(true) {
        if(sum < k) cnt++; // (sum : left집부터 right집까지 금액 합)

        // 오른쪽으로 한 칸씩 이동
        sum -= cost[left];
        left = (left + 1) % n;
        right = (right + 1) % n;
        sum += cost[right];
        if(!left) break; // (한 바퀴 다 돈 경우 종료)
    }
    return cnt;
}

int main() {
    int t, n, m, k;
    cin >> t;

    while(t--) { // 테스트 케이스
        // 마을에 있는 집 개수, 연속된 집 개수, 최소 돈
        cin >> n >> m >> k;

        vector<int> cost(n, 0);
        for(int i = 0; i < n; i++) // 금액 입력력
           cin >> cost[i];
        cout << cnt_steal(n, m, k, cost) << '\n';
    }
    return 0;
}