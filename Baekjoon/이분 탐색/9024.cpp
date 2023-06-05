#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 2 * 1e8 +1;

int binarySearch(int n, int k, vector<int> &s) {
    int cnt = 0, diff = MAX;
    int left = 0, right = n-1;
    while(left < right) {
        int sum = s[left] + s[right]; // 서로 다른 두 정수의 합
        int new_diff = abs(k-sum);
        if(diff > new_diff) { // 1. k에 가장 가까운 정수 발견
            diff = new_diff;
            cnt = 1;
        }
        else if(diff == new_diff) { // 2. 조합수 증가
            cnt++;
        }
        if(sum >= k) {
            right--;
        }
        else {
            left++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n, k;
    vector<int> s;

    cin >> t;
    while(t--) {
        cin >> n >> k;
        s.assign(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        sort(s.begin(), s.end()); // 오름차순 정렬
        cout << binarySearch(n, k, s) << '\n';
    }
    return 0;
}