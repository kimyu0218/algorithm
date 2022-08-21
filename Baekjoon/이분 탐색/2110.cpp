#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> x; // 집 좌표

// 공유기 c개를 설치할 때, 가장 인접한 두 공유기 사이 최대 거리는?
int cnt_router(int k, int n) { // 가장 인접한 두 공유기 사이의 거리가 k일 때 공유기 개수 구하기
    // 첫번째 집에 공유기 설치
    int cnt = 1;
    int pos = x[0];

    for(int i = 1; i < n; i++) {
        if(x[i] - pos < k) continue; // 1. 공유기 설치 불가
        // 2. 공유기 설치
        cnt++; pos = x[i];
    }
    return cnt;
}

int max_distance(int left, int right, int n, int c) {
    int dis = 0; // 최대 거리 저장하는 변수
    while(left <= right) {
        // mid : 가장 인접한 두 공유기 사이의 거리
        int mid = (left + right) / 2;
        int router = cnt_router(mid, n);

        if(router < c) right = mid - 1; // 1. 라우터 다 설치하지 못함 -> 거리 줄이기
        if(router >= c) { // 2. 라우터 다 설치함 -> 거리 늘리기
            dis = mid;
            left = mid + 1;
        }
    }
    return dis;
}

int main() {
    int n, c; // 집 개수, 공유기 개수
    cin >> n >> c;

    x.assign(n, 0);
    for(int i = 0; i < n; i++) // 집 좌표 입력
        cin >> x[i];
    sort(x.begin(), x.end()); // 오름차순

    cout << max_distance(1, x[n-1] - x[0], n, c);
    return 0;
}