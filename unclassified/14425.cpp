#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
set<string> s;

int main() {
    int n, m, result = 0;
    char input[501];
    cin >> n >> m;

    while(n--) { // 집합에 문자열 삽입
        scanf("%s", input);
        s.insert(input);
    }

    while(m--) { // 문자열 검사
        scanf("%s", input);
        if(s.find(input) != s.end()) result++;
    }
    cout << result;
    return 0;
}