#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> tree; // fenwick tree

void update(int idx, int n, ll diff) {
    while(idx <= n) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

ll prefixSum(int idx) { // 누적합 구하기
    ll result = 0;
    while(idx > 0) {
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}

void swap(int &x, int &y) {
    int tmp = y;
    y = x;
    x = tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q, x, y, a, b;
    vector<int> arr;

    cin >> n >> q;
    arr.assign(n+1, 0);
    tree.assign(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, n, arr[i]);
    }

    while(q--) {
        cin >> x >> y >> a >> b;
        // 1. x ~ y 구간합 출력
        if(x > y) { // x가 y보다 큰 경우, swap
            swap(x, y);
        }
        cout << prefixSum(y) - prefixSum(x-1) << '\n';

        // 2. a번째 수 b로 변경
        ll diff = (ll) b - (ll) arr[a];
        arr[a] = b;
        update(a, n, diff);
    }
    return 0;
}