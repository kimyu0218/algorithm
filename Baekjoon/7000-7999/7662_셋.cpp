#include <iostream>
#include <set>

using namespace std;

int main() {
    int t, k, n;
    cin >> t; // 테스트 수

    char op;
    while(t--) {
        cin >> k; // 입력 데이터 수

        multiset<int> s;
        while(k--) {
            cin >> op >> n;

            switch(op) {
                case 'D': // 1. DELETE
                    if(s.empty()) break;
                    else if(n == 1) s.erase(--s.end()); // 1-1. 최댓값 삭제
                    else if(n == -1) s.erase(s.begin()); // 1-2. 최솟값 삭제
                    break;
                case 'I': // 2. INSERT
                    s.insert(n); break;
            }
        }
        if(s.empty()) cout << "EMPTY\n";
        else cout << *(--s.end()) << ' ' << *s.begin() << '\n';
    }
    return 0;
}