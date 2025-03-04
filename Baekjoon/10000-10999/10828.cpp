#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, x;
    string cmd;
    stack<int> s;

    cin >> n;

    while(n--) {
        cin >> cmd;

        if(cmd == "push") {
            cin >> x;
            s.push(x);
        }
        else if(cmd == "pop" || cmd == "top") {
            if(s.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << s.top() << '\n';
            if(cmd == "pop") {
                s.pop();
            }
        }
        else if(cmd == "size") {
            cout << s.size() << '\n';
        }
        else if(cmd == "empty") {
            cout << s.empty() << '\n';
        }
    }
    return 0;
}