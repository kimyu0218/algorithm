#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll binarySearch(int n, vector<vector<int>> &arr) {
    ll cnt = 0;
    vector<int> ab, cd; // ab, cd 용액의 합
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ab.push_back(arr[i][0] + arr[j][1]);
            cd.push_back(arr[i][2] + arr[j][3]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    int size = n*n;
    int left = 0, right = size-1; // left : ab 용액 포인터, right : cd 용액 포인터
    while(left < size && right >= 0) {
        int sum = ab[left] + cd[right];
        if(sum == 0) { // abcd 합이 0인 경우
            int tmp = left;
            ll left_cnt = 0, right_cnt = 0;

            // 1. ab[left]와 같은 값이 몇개 있는가
            while(left < size && ab[left] + cd[right] == 0) { // right 고정
                left_cnt++;
                left++;
            }
            // 2. cd[right]와 같은 값이 몇개 있는가
            while(right >= 0 && ab[tmp] + cd[right] == 0) { // left 고정
                right_cnt++;
                right--;
            }
            cnt += (left_cnt) * (right_cnt);
        }
        else if(sum < 0) { // abcd 합이 0보다 작은 경우
            left++;
        }
        else { // abcd의 합이 0보다 큰 경우
            right--;
        }
    }
    return cnt;
}

int main() {
    int n;
    vector<vector<int>> arr;

    cin >> n;
    arr.assign(n, vector<int> (4, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    cout << binarySearch(n, arr);
    return 0;
}