#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, x;
    cin >> n;

    deque<int> d;

    string command;
    while(n--) {
        cin >> command;
        if(command == "push_front") {
            cin >> x;
            d.push_front(x);
        }
        else if(command == "push_back") {
            cin >> x;
            d.push_back(x);
        }
        else if(command == "pop_front") {
            if(d.empty()) cout << -1 << '\n';
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if(command == "pop_back") {
            if(d.empty()) cout << -1 << '\n';
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else if(command == "size") cout << d.size() << '\n';
        else if(command == "empty") {
            if(d.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(command == "front") {
            if(d.empty()) cout << -1 << '\n';
            else cout << d.front() << '\n';
        }
        else if(command == "back") {
            if(d.empty()) cout << -1 << '\n';
            else cout << d.back() << '\n';
        }
    }
    return 0;
}