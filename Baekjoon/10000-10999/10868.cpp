#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> tree; // segment tree

void init(vector<int> &arr, int node, int start, int end) {
    if(start == end) { // 리프 노드인 경우
        tree[node] = arr[start];
    }
    else { // 리프 노드가 아닌 경우
        int mid = (start + end) / 2;
        init(arr, node*2, start, mid);
        init(arr, node*2+1, mid+1, end);
        tree[node] = min(tree[node*2], tree[node*2+1]); // 최솟값 갱신
    }
}

int query(int node, int start, int end, int left, int right) {
    if(left > end || right < start) { // 해당 구간에서 최솟값 구할 수 없음
        return -1;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int lmin = query(node*2, start, mid, left, right);
    int rmin = query(node*2+1, mid+1, end, left, right);
    if(lmin == -1) {
        return rmin;
    }
    if(rmin == -1) {
        return lmin;
    }
    return min(lmin, rmin);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, a, b, h, tree_size;
    vector<int> arr;

    cin >> n >> m;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));

    arr.assign(n, 0);
    tree.assign(tree_size, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(arr, 1, 0, n-1);

    while(m--) {
        cin >> a >> b;
        cout << query(1, 0, n-1, a-1, b-1) << '\n';
    }
    return 0;
}