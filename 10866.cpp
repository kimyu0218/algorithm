#include <iostream>
#include <deque>

using namespace std;
deque<int> d;

int main() {
    int n, x;
    string cmd;
    cin >> n;

    while(n--) {
        cin >> cmd;

        if(cmd == "push_back") {
            cin >> x;
            d.push_back(x);
            continue;
        }

        if(cmd == "push_front") {
            cin >> x;
            d.push_front(x);
            continue;
        }

        if(cmd == "pop_front") {
            if(d.empty()) cout << -1 << '\n';
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
            continue;
        }

        if(cmd == "pop_back") {
            if(d.empty()) cout << -1 << '\n';
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
            continue;
        }

        if(cmd == "size") {
            cout << d.size() << '\n';
            continue;
        }

        if(cmd == "empty") {
            if(d.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
            continue;
        }

        if(cmd == "front") {
            if(d.empty()) cout << -1 << '\n';
            else cout << d.front() << '\n';
            continue;
        }

        if(cmd == "back") {
            if(d.empty()) cout << -1 << '\n';
            else cout << d.back() << '\n';
            continue;
        }
    }
    return 0;
}