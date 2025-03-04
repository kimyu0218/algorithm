#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntRemove(int k, int d, int n, vector<int> &island) { // 점프하는 최소 거리가 k일 때, 몇 개의 점을 제거하는가
    int cnt = 0, pre = 0;
    for(int i = 0; i < n; i++) {
        if(island[i] - pre < k) { // 점프할 수 있는 경우
            cnt++;
        }
        else { // 점프할 수 없는 경우, 해당 돌섬 밟기
            pre = island[i];
        }
    }
    if(d - pre < k) {
        cnt++;
    }
    return cnt;
}

int binarySearch(int left, int right, int d, int n, int m, vector<int> &island) {
    int answer = 0;
    while(left <= right) {
        int mid = (left + right) / 2; // 점프하는 최소 거리의 최댓값
        int cnt = cntRemove(mid, d, n, island);

        if(cnt <= m) { // m개의 섬 제거 완료
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return answer;
}

int main() {
    int d, n, m;
    vector<int> island;

    cin >> d >> n >> m;
    island.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> island[i];
    }
    sort(island.begin(), island.end()); // 오름차순 정렬

    cout << binarySearch(0, d, d, n, m, island);
    return 0;
}