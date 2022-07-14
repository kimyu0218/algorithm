#include <iostream>

using namespace std;
int bit_mask = 0;

void add(int x) { bit_mask |= (1 << x); } // (OR 연산)
void remove(int x) { bit_mask &= ~(1 << x); } // (AND 연산)
int check(int x) { return bit_mask & (1 << x) ? 1 : 0; }
void toggle(int x) { check(x) ? remove(x) : add(x); }
void all() { bit_mask = (1 << 21) -1; }
void empty() { bit_mask = 0; }

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