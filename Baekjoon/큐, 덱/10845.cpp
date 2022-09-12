#include <iostream>
#include <queue>

using namespace std;

void push(int x, deque<int> &dq) { dq.push_back(x); }

int front(deque<int> &dq) { return (dq.empty() ? -1 : dq.front()); }

int back(deque<int> &dq) { return (dq.empty() ? -1 : dq.back()); }

int pop(deque<int> &dq) {
    int num = front(dq);
    if(num != -1) dq.pop_front();
    return num;
}

int main() {
    int n, x;
    string cmd;
    deque<int> dq;

    cin >> n;
    while(n--) { // 명령
        cin >> cmd;
        if(cmd == "push") {
            cin >> x;
            push(x, dq);
        }
        else if(cmd == "pop") cout << pop(dq) << '\n';
        else if(cmd == "size") cout << dq.size() << '\n';
        else if(cmd == "empty") cout << dq.empty() << '\n';
        else if(cmd == "front") cout << front(dq) << '\n';
        else if(cmd == "back") cout << back(dq) << '\n';
    }
    return 0;
}