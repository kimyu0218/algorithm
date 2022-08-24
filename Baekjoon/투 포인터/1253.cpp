#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;

bool is_good(int left, int right, int idx) {
    while(left < right) {
        // 서로 다른 수의 합이어야 하므로 idx 같을 수 없음
        if(left == idx) { left++; continue; }
        if(right == idx) { right--; continue; }

        int sum = a[left] + a[right];
        if(a[idx] == sum) return true; // 좋은 수 (서로 다른 두 수의 합 가능)
        if(a[idx] < sum) right--; // 1. 만드려는 수보다 큼 -> 작은 숫자 사용
        else left++; // 2. 만드려는 수보다 작음 -> 큰 숫자 사용
    }
    return false;
}

int main() {
    int n, cnt = 0;
    cin >> n;

    a.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) // 좋은 수 세기
        cnt += is_good(0, n-1, i);
    cout << cnt;
    return 0;
}