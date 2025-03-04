#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
vector<ll> tree, lazy;

void init(vector<ll> &arr, int node, int start, int end) {
    if(start == end) { // 리프 노드인 경우
        tree[node] = arr[start];
    }
    else { // 리프 노드가 아닌 경우
        int mid = (start + end) / 2;
        init(arr, node*2, start, mid);
        init(arr, node*2+1, mid+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void updateLazy(int node, int start, int end) {
    if(lazy[node]) { // 변경되어야 하는 노드 발견
        tree[node] += (end-start+1) * lazy[node];
        if(start != end) { // 리프 노드가 아닌 경우
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

    int n, m, k, a, b, c, h, tree_size;
    ll d;
    vector<ll> arr;

    cin >> n >> m >> k;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));

    arr.assign(n, 0);
    tree.assign(tree_size, 0);
    lazy.assign(tree_size, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(arr, 1, 0, n-1);

    for(int i = 0; i < m+k; i++) {
        cin >> a;
        if(a == 1) { // 1. b번째 수부터 c번째 수까지 d 더하기
            cin >> b >> c >> d;
            updateRange(1, 0, n-1, b-1, c-1, d);
        }
        else if(a == 2) { // 2. b번째부터 c번째 수의 구간합 구하기
            cin >> b >> c;
            cout << query(1, 0, n-1, b-1, c-1) << '\n';
        }
    }
    return 0;
}