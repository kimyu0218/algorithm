#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 15;
int l, c;
char crypto[MAX], alphabet[MAX];
bool check[MAX] = { false, };

bool is_ascending(char ch, int cnt) { // 오름차순 여부 판별
    if(cnt == 0) return true;
    if(crypto[cnt-1] < ch) return true;
    return false;
}

bool is_vowel(char ch) { // 모음 여부 판별
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    return false;
}

// (vow : 모음 개수, cons : 자음 개수)
void backtracking(int vow, int cons, int cnt) {
    if(cnt == l) {
        if(vow < 1 || cons < 2) return; // 3. 최소 1개의 모음, 최소 2개의 자음 만족하지 않는 경우 pass
        for(int i = 0; i < cnt; i++)
            cout << crypto[i];
        cout << '\n';
        return;
    }

    for(int i = 0; i < c; i++) {
        if(check[i]) continue; // 1. 이미 사용한 알파벳 pass (중복 허용하지 않음)
        if(!is_ascending(alphabet[i], cnt)) continue; // 2. 내림차순 pass (오름차순만 허용)

        crypto[cnt] = alphabet[i]; check[i] = true; // 암호에 사용
        if(is_vowel(alphabet[i])) backtracking(vow+1, cons, cnt+1);
        else backtracking(vow, cons+1, cnt+1);
        check[i] = false;
    }
}

int main() {
    cin >> l >> c;

    for(int i = 0; i < c; i++)
        cin >> alphabet[i];

    sort(alphabet, alphabet+c);
    backtracking(0, 0, 0);
    return 0;
}