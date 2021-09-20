#include <iostream>

using namespace std;
int bit_mask = 0;

void add(int x) { bit_mask |= (1 << x); }
void remove(int x) { bit_mask &= (1 << x); }
int check(int x) { return bit_mask & (1 << x) ? 1 : 0; }
void toggle(int x) { check(x) ? remove(x) : add(x); }
void empty() { bit_mask = 0; }
void all() { bit_mask = (1 << 21) -1; }

void add_remove_check_toggle(char ch, int x) {
    switch(ch) {
        case 'a': add(x); break;
        case 'r': remove(x); break;
        case 'c':
            cout << check(x) << '\n';
            break;
        case 't': toggle(x); break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, x;
    string cmd;
    cin >> m;

    while(m--) {
        cin >> cmd;
        if(cmd == "add" || cmd == "remove" || cmd == "check" || cmd == "toggle") {
            cin >> x;
            add_remove_check_toggle(cmd[0], x);
        }
        else if(cmd == "empty") empty();
        else if(cmd == "all") all();
    }
    return 0;
}