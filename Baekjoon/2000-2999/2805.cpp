#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<int> h; // 나무 높이 저장하는 배열

// m미터의 나무를 얻기 위해 절단기에 설정해야 할 수 있는 높이의 최댓값은?
// == 절단기에 설정한 높이가 k일 때, m미터의 나무를 얻을 수 있는가?
ll cut_tree(int k, int n) { // 절단기에 설정한 높이가 k일 때 얻을 수 있는 나무 길이 구하기
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        int remain = h[i] - k;
        if(remain <= 0) break;
        sum += (ll) remain;
    }
    return sum;
}

ll max_height(int left, int right, int n, int m) {
    ll ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        ll len = cut_tree(mid, n);

        if(len >= m) { // 1. m미터 이상 가져갈 수 있음 -> 좀 더 잘라보자
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    h.assign(n, 0);
    for(int i = 0; i < n; i++) // 나무 높이 입력
        cin >> h[i];
    sort(h.begin(), h.end(), greater<>());

    cout << max_height(0, h[0], n, m);
    return 0;
}