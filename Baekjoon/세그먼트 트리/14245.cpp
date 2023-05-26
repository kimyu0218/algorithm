#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> tree, lazy;

void init(vector<int> &arr, int node, int start, int end) {
    if(start == end) {
        tree[node] = arr[start];
    }
    else {
        int mid = (start + end) / 2;
        init(arr, node*2, start, mid);
        init(arr, node*2+1, mid+1, end);
        tree[node] = tree[node*2] ^ tree[node*2+1];
    }
}

void updateLazy(int node, int start, int end) {
    if(lazy[node]) {
        tree[node] ^= ((end-start+1)%2) * lazy[node];
        if(start != end) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void updateRange(int node, int start, int end, int left, int right, int diff) {
    updateLazy(node, start, end);
    if(left > end || right < start) {
        return;
    }
    if(left <= start && end <= right) {
        tree[node] ^= ((end-start+1)%2) * diff;
        if(start != end) {
            lazy[node*2] ^= diff;
            lazy[node*2+1] ^= diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, left, right, diff);
    updateRange(node*2+1, mid+1, end, left, right, diff);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

int query(int node, int start, int end, int left, int right) {
    updateLazy(node, start, end);
    if(left > end || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int lxor = query(node*2, start, mid, left, right);
    int rxor = query(node*2+1, mid+1, end, left, right);
    return lxor ^ rxor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, t, a, b, c, h, tree_size;
    vector<int> arr;

    cin >> n;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));

    arr.assign(n, 0);
    tree.assign(tree_size, 0);
    lazy.assign(tree_size, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(arr, 1, 0, n-1);

    cin >> m;
    while(m--) {
        cin >> t;
        if(t == 1) { // 1. [a, b]에 c xor
            cin >> a >> b >> c;
            updateRange(1, 0, n-1, a, b, c);
        }
        else if(t == 2) { // 2. a번째 원소값 출력
            cin >> a;
            cout << query(1, 0, n-1, a, a) << '\n';
        }
    }
    return 0;
}