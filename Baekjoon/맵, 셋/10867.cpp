#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, num;
    cin >> n;

    set<int> s; // (set : 자동 정렬 & 중복된 원소는 한 번만 저장)
    while(n--) {
        cin >> num;
        s.insert(num);
    }

    for(auto iter = s.begin(); iter != s.end(); iter++) // 오름차순 정렬 출력
        cout << *iter << ' ';
    return 0;
}