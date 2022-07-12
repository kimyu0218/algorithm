#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    priority_queue<int, vector<int>, greater<>> pq; // top이 가장 작은 수를 가리킴

    cin >> n;
    int N = n*n;

    while(N--) {
        cin >> x;
        if(pq.size() == n) { // 우선순위 큐의 사이즈가 n인 경우
            int top = pq.top(); // top : n번째로 큰 숫자
            if(top < x) {
                pq.pop();
                pq.push(x);
            }
        }
        else pq.push(x);
    }

    cout << pq.top();
    return 0;
}