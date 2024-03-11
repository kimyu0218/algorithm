#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, x;
    string cmd;
    queue<int> q;

    cin >> n;

    while(n--) {
        cin >> cmd;

        if(cmd == "push") {
            cin >> x;
            q.push(x);
        }
        else if(cmd == "pop" || cmd == "front") {
            if(q.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << q.front() << '\n';
            if(cmd == "pop") {
                q.pop();
            }
        }
        else if(cmd == "size") {
            cout << q.size() << '\n';
        }
        else if(cmd == "empty") {
            cout << q.empty() << '\n';
        }
        else if(cmd == "back") {
            if(q.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << q.back() << '\n';
        }
    }
    return 0;
}