#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> tree; //  fenwick tree

void update(int idx, int n, ll diff) { // idx번째 수 변경
    while(idx <= n) {
        tree[idx] += diff;
        idx += (idx & -idx); // (idx & -idx) : 0이 아닌 마지막 비트
    }
}

ll prefixSum(int idx) { // idx번째까지 누적합 구하기
    ll result = 0;
    while(idx > 0) {
        result += tree[idx];
        idx -= (idx & -idx); // (i & -i) : 0이 아닌 마지막 비트
    }
    return result;
}

int main() {
    int n, m, k, a, b;
    ll c;
    vector<ll> arr;

    cin >> n >> m >> k;
    arr.assign(n+1, 0);
    tree.assign(n+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, n, arr[i]);
    }

    for(int i = 0; i < m+k; i++) {
        cin >> a >> b >> c;
        if(a == 1) { // b번째 수를 c로 변경
            ll diff = c - arr[b];
            arr[b] = c;
            update(b, n, diff);
        }
        else if(a == 2) { // b번째 수부터 c번째 수까지의 합
            cout << prefixSum(c) - prefixSum(b-1) << '\n';
        }
    }
    return 0;
}