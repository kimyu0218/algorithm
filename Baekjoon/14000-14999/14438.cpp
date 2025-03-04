#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> tree;

void init(vector<int> &a, int node, int start, int end) {
    if(start == end) { // 리프 노드의 경우
        tree[node] = a[start];
    }
    else { // 리프 노드가 아닌 경우
        int mid = (start + end) / 2;
        init(a, node*2, start, mid);
        init(a, node*2+1, mid+1, end);
        tree[node] = min(tree[node*2], tree[node*2+1]); // 최솟값 저장
    }
}

void update(int node, int start, int end, int index, int val) {
    if(index < start || index > end) {
        return;
    }
    if(start == end) { // 리프 노드 발견
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, index, val);
    update(node*2+1, mid+1, end, index, val);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

int query(int node, int start, int end, int left, int right) {
    if(left > end || right < start) { // 해당 구간에서 최솟값 구하지 않음
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

    int n, m, h, tree_size, option, u, v;
    vector<int> a;

    cin >> n;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));

    a.assign(n, 0);
    tree.assign(tree_size, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a, 1, 0, n-1);

    cin >> m;
    while(m--) {
        cin >> option >> u >> v;
        if(option == 1) { // u번째 수 v로 변경
            update(1, 0, n-1, u-1, v);
        }
        else if(option == 2) { // i부터 j까지 크기가 가장 작은 값 출력
            cout << query(1, 0, n-1, u-1, v-1) << '\n';
        }
    }
    return 0;
}