#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 15;

char result[MAX];
char ch[MAX];
bool visited[MAX];

bool is_valid_cipher(int l) {
    int v_cnt = 0;
    for(int i = 0; i < l; i++) {
        if(result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u') {
            v_cnt++;
        }
    }
    return l - v_cnt >= 2 && v_cnt >= 1;
}

void backtracking(int idx, int l, int start, int c) {
    if(idx == l) {
        if(is_valid_cipher(l)) {
            for(int i = 0; i < l; i++) {
                cout << result[i];
            }
            cout << '\n';
        }
        return;
    }

    for(int i = start; i < c; i++) {
        if(visited[i]) {
            continue;
        }
        visited[i] = true;
        result[idx] = ch[i];
        backtracking(idx + 1, l, i + 1, c);
        visited[i] = false;
    }
}

void solution(int l, int c) {
    sort(ch, ch + c);
    backtracking(0, l, 0, c);
}

int main() {
    int l, c;

    cin >> l >> c;
    for(int i = 0; i < c; i++) {
        cin >> ch[i];
    }

    solution(l, c);
    return 0;
}