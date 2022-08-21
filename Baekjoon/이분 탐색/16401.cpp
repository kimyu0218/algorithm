#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> len; // 과자 길이 저장하는 배열

// 조카 m명에게 나누어 줄 수 있는 막대 과자의 최대 길이는?
// == 막대 과자 길이가 k일 때, 나누어 줄 수 있는 조카 수는?
int cnt_nephew(int k, int n) { // 막대 과자 길이가 k일 대 나누어 줄 수 있는 조카 수 구하기
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(len[i]/k) cnt += len[i]/k;
    }
    return cnt;
}

int max_len(int left, int right, int n, int m) {
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int nephew = cnt_nephew(mid, n);

        if(nephew < m) right = mid - 1; // 1. 모든 조카에게 나누어 주지 못함 -> 길이 줄이기
        if(nephew >= m) { // 2. 모든 조카에게 나누어 줌 -> 길이 늘리기
            ans = mid;
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int m, n; // 조카 수, 과자 수
    cin >> m >> n;

    len.assign(n, 0);
    for(int i = 0; i < n; i++) // 과자 길이 입력
        cin >> len[i];
    sort(len.begin(), len.end()); // 과자 길이 오름차순 정렬

    cout << max_len(1, len[n-1], n, m);
    return 0;
}