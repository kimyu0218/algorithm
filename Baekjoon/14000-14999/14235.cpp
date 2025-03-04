#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, a, w;
    priority_queue<int> pq;

    cin >> n;
    while(n--) {
        cin >> a;
        if(a == 0) { // 아이들 만난 경우, 선물 주기
            if(pq.empty()) { // 줄 선물이 없는 경우
                cout << -1 << '\n';
            }
            else { // 가장 가치가 큰 선물 주기
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else { // 거점지인 경우, 선물 충전하기
            while(a--) {
                cin >> w;
                pq.push(w);
            }
        }
    }
    return 0;
}