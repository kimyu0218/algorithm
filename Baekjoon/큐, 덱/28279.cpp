#include <iostream>
#include <deque>

using namespace std;

int front(deque<int> &dq) {
   return dq.empty() ? -1 : dq.front();
}

int back(deque<int> &dq) {
   return dq.empty() ? -1 : dq.back();
}

void pop_front(deque<int> &dq) {
    if(!dq.empty()) {
        dq.pop_front();
    }
}

void pop_back(deque<int> &dq) {
    if(!dq.empty()) {
        dq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x, cmd;
    deque<int> dq;
    
    cin >> n;
    while(n--) {
        cin >> cmd;
        
        switch(cmd) {
            case 1:
                cin >> x;
                dq.push_front(x);
                break;
            case 2:
                cin >> x;
                dq.push_back(x);
                break;
            case 3:
                cout << front(dq) << '\n';
                pop_front(dq);
                break;
            case 4:
                cout << back(dq) << '\n';
                pop_back(dq);
                break;
            case 5:
                cout << dq.size() << '\n';
                break;
            case 6:
                cout << dq.empty() << '\n';
                break;
            case 7:
                cout << front(dq) << '\n';
                break;
            case 8:
                cout << back(dq) << '\n';
                break;
        }
    }
    return 0;
}