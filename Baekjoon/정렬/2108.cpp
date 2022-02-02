#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int cnt[8001] = {0, }; // 빈도 카운트하는 배열

int findMode() { // 최빈값 찾기
    int max = 0, max_cnt = 0, mode = 0;
    for(int i = 0; i < 8001; i++) {
        if(max < cnt[i]) { // 최댓값 갱신
            max = cnt[i]; max_cnt = 1;
            mode = i - 4000;
        }
        else if(max == cnt[i]) max_cnt++; // 기존의 최댓값과 동일한 경우

        // (최빈값이 여러 개인 경우 두번째로 작은 값이 최빈값)
        if(max == cnt[i] && max_cnt == 2) mode = i - 4000;
    }
    return mode;
}

int main() {
    int n, sum = 0;
    cin >> n;

    vector<int> arr;
    arr.assign(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        cnt[arr[i] + 4000]++;
    }

    sort(arr.begin(), arr.end()); // 오름차순 정렬

    cout << round((double) sum/n) << '\n';    // 산술 평균
    cout << arr[n/2] << '\n';                 // 중앙값
    cout << findMode() << '\n';               // 최빈값
    cout << arr[n-1] - arr[0];                // 범위

    return 0;
}