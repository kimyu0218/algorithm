#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    if(p1.second != p2.second) return p1.second < p2.second; // 1. 종료 시간이 빠른 순
    return p1.first < p2.first; // 2. 시작 시간이 빠른 순
};

int meeting(int n, vector<pair<int, int>> time_table) { // 회의 개수 세기
    int cnt = 1, end = time_table[0].second;

    for(int i = 1; i < n; i++) {
        if(end > time_table[i].first) continue; // 회의를 할 수 없는 경우
        cnt++; end = time_table[i].second;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> time_table(n, {0, 0});
    for(int i = 0; i < n; i++) // 회의 정보 입력
        cin >> time_table[i].first >> time_table[i].second;
    sort(time_table.begin(), time_table.end(), cmp);

    cout << meeting(n, time_table);
    return 0;
}