#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> tree;

void update(int idx, int n, int diff) {
    while(idx <= n) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

ll prefixSum(int idx) {
    ll result = 0;
    while(idx > 0) {
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q, option, p, x;
    vector<int> arr;

    cin >> n >> q;
    arr.assign(n+1, 0);
    tree.assign(n+1, 0);
    while(q--) {
        cin >> option >> p >> x;
        if(option == 1) { // 1. 생후 p일에 x 추가
            arr[p] += x;
            update(p, n, x);
        }
        else if(option == 2) { // 2. 생후 p일부터 q일까지 변화한 양 출력
            cout << prefixSum(x) - prefixSum(p-1) << '\n';
        }
    }
    return 0;
}