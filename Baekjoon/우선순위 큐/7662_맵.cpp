#include <iostream>
#include <map>

using namespace std;

int main() {
    int t, k, n;
    cin >> t; // 테스트 수

    char op;
    while(t--) {
        cin >> k; // 입력 데이터 수

        map<int, int> m;
        while(k--) {
            cin >> op >> n;

            switch(op) {
                case 'D': // 1. DELETE
                    if(m.empty()) break;
                    else if(n == 1) { // 1-1. 최댓값 삭제
                        auto iter = --m.end();
                        m[iter->first]--;
                        if(m[iter->first] == 0) m.erase(iter->first);
                    }
                    else if(n == -1) { // 1-2. 최솟값 삭제
                        auto iter = m.begin();
                        m[iter->first]--;
                        if(m[iter->first] == 0) m.erase(iter->first);
                    }
                    break;
                case 'I': // 2. INSERT
                    m[n]++; break;
            }
        }
        if(m.empty()) cout << "EMPTY\n";
        else cout << (--m.end())->first << ' ' << m.begin()->first << '\n';
    }
    return 0;
}