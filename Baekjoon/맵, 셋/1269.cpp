#include <iostream>
#include <map>

using namespace std;

int difference(map<int, int> a, map<int, int> b) {
    int cnt = 0; // 원소 개수 카운트
    for(auto iter = a.begin(); iter != a.end(); iter++) {
        if(!b[iter->first]) cnt++; // a-b
    }
    for(auto iter = b.begin(); iter != b.end(); iter++) {
        if(!a[iter->first]) cnt++; // b-a
    }
    return cnt;
}

int main() {
    int n, m; // A 원소 개수, B 원소 개수
    cin >> n >> m;

    map<int, int> a, b;
    int num;
    while(n--) { // A 원소 입력
        cin >> num;
        a[num]++;
    }

    while(m--) { // B 원소 입력
        cin >> num;
        b[num]++;
    }

    cout << difference(a, b);
    return 0;
}