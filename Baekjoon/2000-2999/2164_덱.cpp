#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> d;
    for(int i = 1; i <= n; i++) d.push_back(i); // 카드 오름차순으로 push

    while(true) {
        // 1. 맨 앞의 숫자 버리기
        if(d.size() == 1) {
            cout << d.front();
            break;
        }
        d.pop_front();

        // 2. 맨 앞의 숫자 맨 뒤로 옮기기
        if(d.size() == 1) {
            cout << d.front();
            break;
        }
        int front = d.front(); d.pop_front();
        d.push_back(front);
    }
    return 0;
}