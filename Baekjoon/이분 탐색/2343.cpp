#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> len;

// 블루레이 m개가 있을 때, 가능한 블루레이의 최소 크기는?
// == 블루레이의 길이가 k일 때, 블루레이 m개를 사용하여 모든 강의를 담을 수 있는가?
int cnt_blueray(int k, int n) { // 블루레이의 길이가 k일 때 모든 강의를 담기 위해 필요한 블루레이 개수 구하기
    int cnt = 0, tmp = 0;
    for(int i = 0; i < n; i++) {
        if(tmp + len[i] > k) { cnt++; tmp = len[i]; } // 1. 현재 블루레이 길이 초과 -> 새로운 블루레이 사용
        else tmp += len[i]; // 2. 블루레이에 현재 강의 추가
    }
    return cnt + 1; // (tmp에 들어있는) 마지막 블루레이 추가
}

int min_len(int left, int right, int n, int m) {
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int blueray = cnt_blueray(mid, n);

        if(blueray <= m) { // 1. 블루레이 개수 만족 -> 블루레이 길이 줄이기
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1; // 2. 블루레이 개수 초과 -> 블루레이 길이 늘리기
    }
    return ans;
}

int main() {
    int n, m, longest = 0;
    cin >> n >> m;

    len.assign(n, 0);
    for(int i = 0; i < n; i++) { // 강의 길이 입력
        cin >> len[i];
        longest = max(longest, len[i]);
    }

    cout << min_len(longest, longest * n, n, m);
    return 0;
}