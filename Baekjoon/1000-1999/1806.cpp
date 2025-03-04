#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e9;
vector<int> sum; // 누적합 저장 (sum[i] : 1부터 i까지 누적합)

int two_pointer(int left, int right, int s, int n) {
    int ans = MAX;
    while(left < right && right <= n) {
        int part_sum = sum[right] - sum[left]; // 연속된 부분합
        if(part_sum >= s) { // 1. 합 s 이상 -> 길이 줄이기
            ans = min(ans, right - left);
            left++;
        }
        else right++; // 2. 합 s 미만 -> 길이 늘리기
    }
    return ((ans == MAX) ? 0 : ans);
}

int main() {
    int n, s, num;
    cin >> n >> s;

    sum.assign(n+1, 0);
    for(int i = 1; i <= n; i++) { // 수열 입력
        cin >> num;
        sum[i] = sum[i-1] + num;
    }

    cout << two_pointer(0, 1, s, n);
    return 0;
}