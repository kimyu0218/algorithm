#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> tree; // fenwick tree

void modify(int idx, int n, ll diff) { // modify 함수 실행
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

void swap(int &i, int &j) { // swap
    int tmp = i;
    i = j;
    j = tmp;
}

ll sum(int start, int end) { // sum 함수 실행
    return prefixSum(end) - prefixSum(start);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, cmd, i, j;
    vector<int> arr;

    cin >> n >> m;
    arr.assign(n+1, 0);
    tree.assign(n+1, 0);
    while(m--) {
        cin >> cmd >> i >> j;
        if(cmd == 0) { // 1. sum 함수 실행
            if(i > j) { // i가 j보다 큰 경우, swap
                swap(i, j);
            }
            cout << sum(i-1, j) << '\n';
        }
        else if(cmd == 1) { // 2. modify 함수 실행
            ll diff = j - arr[i];
            arr[i] = j;
            modify(i, n, diff);
        }
    }
    return 0;
}