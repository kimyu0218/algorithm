#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
vector<ll> tree; // segment tree

void update(int node, int start, int end, int index, int diff) {
    if(index < start || index > end) {
        return;
    }
    tree[node] += diff;
    if(start != end) {
        int mid = (start + end) / 2;
        update(node*2, start, mid, index, diff);
        update(node*2+1, mid+1, end, index, diff);
    }
}

ll query(int node, int start, int end, int left, int right) {
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

    int n, q, h, tree_size, option, p, x;
    vector<int> arr;

    cin >> n >> q;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));
    arr.assign(n, 0);
    tree.assign(tree_size, 0);

    while(q--) {
        cin >> option >> p >> x;
        if(option == 1) { // 1 p x : 생후 p일에 x 추가
            arr[p-1] += x;
            update(1, 0, n-1, p-1, x);
        }
        else if(option == 2) { // 2 p x : 생후 p일부터 q일까지 변화한 양 출력
            cout << query(1, 0, n-1, p-1, x-1) << '\n';
        }
    }
    return 0;
}