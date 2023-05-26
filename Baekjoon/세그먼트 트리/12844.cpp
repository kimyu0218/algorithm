#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> tree, lazy;

void init(vector<int> &a, int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    }
    else {
        int mid = (start + end) / 2;
        init(a, node*2, start, mid);
        init(a, node*2+1, mid+1, end);
        tree[node] = tree[node*2] ^ tree[node*2+1];
    }
}

void updateLazy(int node, int start, int end) {
    if(lazy[node]) {
        // 홀수번 xor 하면 a, 짝수번 xor 하면 0
        tree[node] ^= ((end-start+1)%2) * lazy[node];
        if(start != end) { // 리프 노드가 아닌 경우
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
        // 홀수번 xor 하면 a, 짝수번 xor 하면 0
        tree[node] ^= ((end-start+1)%2) * diff;
        if(start != end) { // 리프 노드가 아닌 경우
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
        return 0; // a xor 0 = a
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
        cin >> option >> i >> j;
        if(option == 1) { // 1 i j k : i번째부터 j번째까지 k xor
            cin >> k;
            updateRange(1, 0, n-1, i, j, k);
        }
        else if(option == 2) { // 2 i j : i번째부터 j번째까지 xor
            cout << query(1, 0, n-1, i, j) << '\n';
        }
    }
    return 0;
}