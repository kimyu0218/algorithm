#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rest_area;

// m개의 휴게소를 더 지을 때, 휴게소가 없는 구간의 길이의 최댓값의 최솟값은?
// == 휴게소가 없는 구간의 길이의 최댓값이 k일 때, m개의 휴게소를 지을 수 있는가?
int cnt_rest_area(int k, int n) {
    int cnt = 0;
    for(int i = 1; i < n+2; i++)
        cnt += (rest_area[i] - rest_area[i-1] - 1) / k;
    return cnt;
}

int min_distance(int left, int right, int n, int m) {
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int cnt = cnt_rest_area(mid, n);

        if(cnt <= m) { // 1. m개 이하의 휴게소 필요 (설치 가능) -> 최솟값 줄이기
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1; // 2. 휴게소 개수 부족 (설치 불가) -> 최솟값 늘리기
    }
    return ans;
}

int main() {
    int n, m, l;
    cin >> n >> m >> l;

    rest_area.assign(n+2, 0);
    for(int i = 1; i <= n; i++)
        cin >> rest_area[i];
    rest_area[n+1] = l;
    sort(rest_area.begin(), rest_area.end());

    cout << min_distance(1, l-1, n, m);
    return 0;
}