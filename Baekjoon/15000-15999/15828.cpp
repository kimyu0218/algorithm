#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, x;
    cin >> n;

    queue<int> buffer;

    while(true) {
        cin >> x;
        if(x == -1) { // 종료 조건
            break;
        }
        if(x == 0) { // 패킷 하나 처리
            buffer.pop();
        }
        else {
            if(buffer.size() >= n) {
                while(buffer.size() > n) {
                    buffer.pop();
                }
            }
            else {
                buffer.push(x);
            }
        }
    }

    if(buffer.empty()) {
        cout << "empty";
    }
    else {
        while(!buffer.empty()) {
            cout << buffer.front() << ' ';
            buffer.pop();
        }
    }
    return 0;
}