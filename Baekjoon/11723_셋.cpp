#include <iostream>
#include <set>

using namespace std;
set<int> s;

void add(int x) { s.insert(x); }
void remove(int x) { s.erase(x); }
bool check(int x) { return s.find(x) != s.end(); }
void toggle(int x) {
    if(check(x)) remove(x);
    else add(x);
}
void all() {
    for(int i = 1; i <= 20; i++) add(i);
}
void empty() { s.clear(); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, x;
    string op;
    cin >> m;

    while(m--) {
        cin >> op;
        if(op == "add") {
            cin >> x;
            add(x);
        }
        else if(op == "remove") {
            cin >> x;
            remove(x);
        }
        else if(op == "check") {
            cin >> x;
            cout << check(x) << '\n';
        }
        else if(op == "toggle") {
            cin >> x;
            toggle(x);
        }
        else if(op == "all") all();
        else if(op == "empty") empty();
    }
    return 0;
}