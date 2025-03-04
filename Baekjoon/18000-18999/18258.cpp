#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    string command;
    cin >> n;

    queue<int> q;
    while(n--) {
        cin >> command;
        if(command == "push") {
            cin >> x;
            q.push(x);
        }
        else if(command == "pop") {
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(command == "size") cout << q.size() << '\n';
        else if(command =="empty") {
            if(q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(command == "front") {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if(command == "back") {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
    return 0;
}