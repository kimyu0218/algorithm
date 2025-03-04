#include <iostream>
#include <set>

using namespace std;

int cnt_string(string s) {
    set<string> dic; // 서로 다른 문자열 개수

    int size = s.length();
    for(int i = 0; i < size; i++) { // i : 부분 문자열 시작 위치
        int sub_len = size-i;
        for(int j = sub_len; j > 0; j--)
            dic.insert(s.substr(i, j));
    }
    return dic.size();
}

int main() {
    string s;
    cin >> s;

    cout << cnt_string(s);
    return 0;
}