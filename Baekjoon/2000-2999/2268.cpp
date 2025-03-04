#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
vector<ll> tree; // segment tree;

void modify(int node, int start, int end, int index, int diff) {
    if(index < start || index > end) {
        return;
    }
    tree[node] += diff;
    if(start != end) {
        int mid = (start + end) / 2;
        modify(node*2, start, mid, index, diff);
        modify(node*2+1, mid+1, end, index, diff);
    }
}

ll sum(int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    ll lsum = sum(node*2, start, mid, left, right);
    ll rsum = sum(node*2+1, mid+1, end, left, right);
    return lsum + rsum;
}

void swap(int &i, int &j) {
    int tmp = i;
    i = j;
    j = tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, cmd, i, j, h, tree_size;
    vector<int> a;

    cin >> n >> m;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));

    a.assign(n, 0);
    tree.assign(tree_size, 0);

    while(m--) {
        cin >> cmd >> i >> j;
        if(cmd == 0) { // sum
            if(i > j) {
                swap(i, j);
            }
            cout << sum(1, 0, n-1, i-1, j-1) << '\n';
        }
        else if(cmd == 1) { // modify
            int diff = j - a[i-1];
            a[i-1] = j;
            modify(1, 0, n-1, i-1, diff);
        }
    }
    return 0;
}