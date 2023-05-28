#include <iostream>
#include <algorithm>

using namespace std;

void bruteforce(string s, string t) {
    if(s.length() == t.length()) { // 기저조건
        if(s == t) { // s를 t로 바꿀 수 있는 경우, 곧바로 1출력 후 종료
            cout << 1;
            exit(0);
        }
        return;
    }

    int idx = t.length()-1;
    if(t[idx] == 'A') { // t의 뒷글자가 a인 경우
        string tmp = t.substr(0, idx);
        bruteforce(s, tmp);
    }
    if(t[0] == 'B') { // t의 앞글자가 b인 경우
        string tmp = t.substr(1, idx);
        reverse(tmp.begin(), tmp.end());
        bruteforce(s, tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    bruteforce(s, t);
    cout << 0;
    return 0;
}