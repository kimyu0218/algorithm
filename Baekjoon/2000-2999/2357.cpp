#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> min_tree, max_tree;

void minInit(vector<int> &arr, int node, int start, int end) {
    if(start == end) { // 리프 노드인 경우
        min_tree[node] = arr[start];
    }
    else { // 리프 노드가 아닌 경우
        int mid = (start + end) / 2;
        minInit(arr, node*2, start, mid);
        minInit(arr, node*2+1, mid+1, end);
        min_tree[node] = min(min_tree[node*2], min_tree[node*2+1]);
    }
}

void maxInit(vector<int> &arr, int node, int start, int end) {
    if(start == end) { // 리프 노드인 경우
        max_tree[node] = arr[start];
    }
    else { // 리프 노드가 아닌 경우
        int mid = (start + end) / 2;
        maxInit(arr, node*2, start, mid);
        maxInit(arr, node*2+1, mid+1, end);
        max_tree[node] = max(max_tree[node*2], max_tree[node*2+1]);
    }
}

int minQuery(int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return -1;
    }
    if(left <= start && end <= right) {
        return min_tree[node];
    }
    int mid = (start + end) / 2;
    int lmin = minQuery(node*2, start, mid, left, right);
    int rmin = minQuery(node*2+1, mid+1, end, left, right);
    if(lmin == -1) {
        return rmin;
    }
    if(rmin == -1) {
        return lmin;
    }
    return min(lmin, rmin);
}

int maxQuery(int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return -1;
    }
    if(left <= start && end <= right) {
        return max_tree[node];
    }
    int mid = (start + end) / 2;
    int lmax = maxQuery(node*2, start, mid, left, right);
    int rmax = maxQuery(node*2+1, mid+1, end, left, right);
    if(lmax == -1) {
        return rmax;
    }
    if(rmax == -1) {
        return lmax;
    }
    return max(lmax, rmax);
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
    min_tree.assign(tree_size, 0);
    max_tree.assign(tree_size, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    minInit(arr, 1, 0, n-1);
    maxInit(arr, 1, 0, n-1);

    while(m--) {
        cin >> a >> b;
        cout << minQuery(1, 0, n-1, a-1, b-1) << ' ' << maxQuery(1, 0, n-1, a-1, b-1) << '\n';
    }
    return 0;
}