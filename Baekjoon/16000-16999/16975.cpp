#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
vector<ll> tree, lazy;

void init(vector<int> &a, int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    }
    else {
        int mid = (start + end) / 2;
        init(a, node*2, start, mid);
        init(a, node*2+1, mid+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void updateLazy(int node, int start, int end) {
    if(lazy[node]) {
        tree[node] += (end-start+1) * lazy[node];
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void updateRange(int node, int start, int end, int left, int right, ll diff) {
    updateLazy(node, start, end);
    if(left > end || right < start) {
        return;
    }
    if(left <= start && end <= right) {
        tree[node] += (end-start+1) * diff;
        if(start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, left, right, diff);
    updateRange(node*2+1, mid+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int node, int start, int end, int left, int right) {
    updateLazy(node, start, end);
    if(left > end || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    ll lsum = query(node*2, start, mid, left, right);
    ll rsum = query(node*2+1, mid+1, end, left, right);
    return lsum + rsum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, option, i, j, k, h, tree_size;
    vector<int> a;

    cin >> n;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));

    a.assign(n, 0);
    tree.assign(tree_size, 0);
    lazy.assign(tree_size, 0);
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a, 1, 0, n-1);

    cin >> m;
    while(m--) {
        cin >> option;
        if(option == 1) { // 1 i j k : i번째부터 j번째까지 k 더하기
            cin >> i >> j >> k;
            updateRange(1, 0, n-1, i-1, j-1, k);
        }
        else if(option == 2) { // 2 x : x번째 수 출력
            cin >> k;
            cout << query(1, 0, n-1, k-1, k-1) << '\n';
        }
    }
    return 0;
}