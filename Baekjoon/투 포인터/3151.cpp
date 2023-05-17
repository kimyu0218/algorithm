#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll cntTeam(int n, vector<int> &a) {
    ll cnt = 0; // 합이 0이 되는 3인조를 만드는 경우의 수

    // 3인조 : i번째 사람 + left번째 사람 + right번째 사람
    for(int i = 0; i < n-2; i++) {
        int left = i+1, right = n-1;
        while(left < right) {
            int sum = a[i] + a[left] + a[right];
            if(sum == 0) { // 1. 합이 0이 되는 경우
                // 1-1. a[left]와 a[right]가 같은 경우
                // ex. -4 2 2 2 2
                if(a[left] == a[right]) {
                    cnt += (right - left); // left와 (left+1 ~ right) 선택
                    left++;
                }
                // 1-2. a[left]와 a[right]가 다른 경우
                // ex. -4 -1 -1 3 3
                else {
                    int r_cnt = 1, l_cnt = 1;
                    int a_left = a[left], a_right = a[right];
                    while(a_left == a[++left]) { // a[left]와 같은 수 세기
                        l_cnt++;
                    }
                    while(a_right == a[--right]) { // a[right]와 같은 수 세기
                        r_cnt++;
                    }
                    cnt += (l_cnt * r_cnt); // 경우의 수 더하기
                }
            }
            else if(sum > 0) { // 2. 합이 0보다 큰 경우
                right--;
            }
            else { // 3. 합이 0보다 큰 경우
                left++;
            }
        }
    }
    return cnt;
}

int main() {
    int n;
    vector<int> a;

    cin >> n;
    a.assign(n, 0);
    for(int i = 0; i < n; i++) { // 코딩 실력 입력
        cin >> a[i];
    }

    sort(a.begin(), a.end()); // 코딩 실력 오름차순 정렬
    cout << cntTeam(n, a);
    return 0;
}