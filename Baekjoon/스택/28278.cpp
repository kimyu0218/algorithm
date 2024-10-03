#include <iostream>
#include <stack>

using namespace std;

int top(stack<int> &s) {
    return s.empty() ? -1 : s.top();
}

int pop(stack<int> &s) {
    int t = top(s);
    if(!s.empty()) {
        s.pop();
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x, cmd;
    stack<int> s;
    
    cin >> n;
    while(n--) {
        cin >> cmd;
        
        switch(cmd) {
            case 1:
                cin >> x;
                s.push(x);
                break;
            case 2:
                cout << pop(s) << '\n';
                break;
            case 3:
                cout << s.size() << '\n';
                break;
            case 4:
                cout << s.empty() << '\n';
                break;
            case 5:
                cout << top(s) << '\n';
                break;
        }
    }
    return 0;
}