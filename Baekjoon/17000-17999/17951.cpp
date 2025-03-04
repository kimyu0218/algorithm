#include <iostream>
#include <vector>

using namespace std;

int cntGroup(int mid, int n, vector<int> &x) { // 그룹 최솟값이 mid일 때, 몇개의 그룹을 만들 수 있는가
    int cnt = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        if(sum + x[i] >= mid) {
            cnt++;
            sum = 0;
        }
        else {
            sum += x[i];
        }
    }
    return cnt;
}

int binarySearch(int left, int right, int n, int k, vector<int> &x) {
    int answer = 0;
    while(left <= right) {
        int mid = (left + right) / 2; // 그룹 최솟값
        int group = cntGroup(mid, n, x);

        if(group >= k) { // 1. k개의 그룹을 만들 수 있는 경우, 최솟값 늘리기
            answer = mid;
            left = mid + 1;
        }
        else { // 2. k개의 그룹을 만들 수 없는 경우, 최솟값 줄이기
            right = mid - 1;
        }
    }
    return answer;
}

int main() {
    int n, k, sum = 0;
    vector<int> x;

    cin >> n >> k;
    x.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    cout << binarySearch(0, sum, n, k, x);
    return 0;
}