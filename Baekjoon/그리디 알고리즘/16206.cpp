#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int &i1, int &i2) {
    // 1. 10의 배수인 케이크 먼저
    if((i1 % 10) && !(i2 % 10)) return false;
    if(!(i1 % 10) && (i2 % 10)) return true;
    // 2. 오름차순
    return i1 < i2;
}

int cake(int n, int m, vector<int> len) {
    int cnt = 0; // 케이크 개수 저장하는 변수

    for(int i = 0; i < n; i++) {
        int cut = (len[i] % 10) ? len[i]/10 : len[i]/10-1; // i번째 케이크 자르는 횟수 (10보다 작은 길이 버림)
        int piece = len[i]/10; // 길이 10짜리 케이크 개수

        if(m - cut < 0) return (cnt + m);
        cnt += piece; // 길이 10짜리 케이크 수 더하기
        m -= cut; // 자른 횟수 지우기
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> len(n, 0);
    for(int i = 0; i < n; i++) // 케이크 길이 입력
        cin >> len[i];
    sort(len.begin(), len.end(), cmp);

    cout << cake(n, m, len);
    return 0;
}