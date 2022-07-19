#include <iostream>

using namespace std;

const int CURRENT = 100;
const int MAX = 500000;
bool breakdown[10] = { false, }; // 고장 여부 저장

bool possible(int num) { // 이동할 수 있는 채널인가
    string s = to_string(num);
    for(int i = 0; i < s.length(); i++) {
        if(breakdown[s[i]-'0']) return false;
    }
    return true;
}

int press(int n) { // 버튼 클릭수 세기
    int cnt = abs(n - CURRENT);
    for(int i = 0; i <= 2 * MAX; i++) {
        // 1. to_string(i).length() : 리모컨으로 숫자 누르기
        // 2. abs(n-i) : 리모컨 +/- 버튼으로 이동하기
        if(possible(i))
            cnt = min(cnt, (int) to_string(i).length() + abs(n - i));
    }
    return cnt;
}

int main() {
    int n, m, num;
    cin >> n >> m;

    while (m--) {
        cin >> num;
        breakdown[num] = true;
    }
    cout << press(n);
    return 0;
}