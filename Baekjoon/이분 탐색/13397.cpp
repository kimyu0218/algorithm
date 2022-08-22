#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10000;
vector<int> arr;

// m개의 구간을 만들었을 때, 구간 점수의 최댓값의 최솟값은?
// == 구간 점수의 최댓값이 k일 때, m개의 구간을 만들 수 있는가?
int cnt_partition(int k, int n) { // 구간 점수의 최댓값 k일 때 만들 수 있는 구간 개수 구하기
    int cnt = 0, tmp_min = arr[0], tmp_max = arr[0];
    for(int i = 1; i < n; i++) {
        tmp_max = max(arr[i], tmp_max);
        tmp_min = min(arr[i], tmp_min);
        // 구간의 점수 : 구간에 속한 수의 최댓값과 최솟값의 차 (tmp_max - tmp_min)
        if(tmp_max - tmp_min > k) {
            cnt++;
            tmp_min = arr[i];
            tmp_max = arr[i];
        }
    }
    return cnt + 1; // (tmp) 마지막 구간 추가
}

int min_score(int left, int right, int n, int m) {
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int partition = cnt_partition(mid, n);

        if(partition > m) left = mid + 1; // 1. m개를 초과하는 구간이 나온 경우
        else { // 2. m개 이하의 구간을 만든 경우 -> 최댓값 크기 줄이기
            ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    arr.assign(n, 0);
    int arr_min = MAX, arr_max = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr_min = min(arr_min, arr[i]);
        arr_max = max(arr_max, arr[i]);
    }

    cout << min_score(0, arr_max - arr_min, n, m);
    return 0;
}