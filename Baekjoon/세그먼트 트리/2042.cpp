#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
vector<ll> tree; // segment tree

void init(vector<ll> &arr, int node, int start, int end) {
    if(start == end) { // 리프 노드인 경우, 수 하나만 저장
        tree[node] = arr[start];
    }
    else { // 리프 노드가 아닌 경우, 왼쪽 + 오른쪽 서브트리의 합
        int mid = (start + end) / 2;
        init(arr, node*2, start, mid);
        init(arr, node*2+1, mid+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update(int node, int start, int end, int index, ll diff) {
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

    int n, m, k, h, a, b, tree_size;
    ll c;
    vector<ll> arr;

    cin >> n >> m >> k;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));

    arr.assign(n, 0);
    tree.assign(tree_size, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(arr, 1, 0, n-1);

    for(int i = 0; i < m+k; i++) {
        cin >> a >> b >> c;
        if(a == 1) { // b번째 수 c로 변경
            ll diff = c - arr[b-1];
            arr[b-1] = c;
            update(1, 0, n-1, b-1, diff);
        }
        else if(a == 2) { // b번째 수부터 c번째 수까지의 합
            cout << query(1, 0, n-1, b-1, c-1) << '\n';
        }
    }
    return 0;
}