#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i); // 카드 오름차순으로 push

    while(true) {
        // 1. 맨 앞의 숫자 버리기
        if(q.size() == 1) {
            cout << q.front();
            break;
        }
        q.pop();

        // 2. 맨 앞의 숫자 맨 뒤로 옮기기
        if(q.size() == 1) {
            cout << q.front();
            break;
        }
        int front = q.front(); q.pop();
        q.push(front);
    }
    return 0;
}