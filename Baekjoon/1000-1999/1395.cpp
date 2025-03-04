#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> state;
vector<int> tree, lazy;

void updateLazy(int node, int start, int end) {
    if(lazy[node] % 2) { // 스위치 변경횟수가 홀수인 경우 (== 스위치가 켜진 경우)
        tree[node] = (end-start+1) - tree[node];
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void updateRange(int node, int start, int end, int left, int right) {
    updateLazy(node, start, end);
    if(left > end || right < start) {
        return;
    }
    if(left <= start && end <= right) {
        tree[node] = (end-start+1) - tree[node];
        if(start != end) { // 리프 노드가 아닌 경우, 하위 노드에 변경사항 전달
            // 스위치 상태 반전
            lazy[node*2] += 1;
            lazy[node*2+1] += 1;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, left, right);
    updateRange(node*2+1, mid+1, end, left, right);
    tree[node] = tree[node*2] + tree[node*2+1];
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
    int lsum = query(node*2, start, mid, left, right);
    int rsum = query(node*2+1, mid+1, end, left, right);
    return lsum + rsum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, o, s, t, h, tree_size;

    cin >> n >> m;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));

    state.assign(n, false);
    tree.assign(tree_size, 0);
    lazy.assign(tree_size, 0);
    while(m--) {
        cin >> o >> s >> t;
        if(o == 0) { // 1. s번부터 t번 스위치 상태 반전
            updateRange(1, 0, n-1, s-1, t-1);
        }
        else if(o == 1) { // 2. s번부터 t번 스위치까지 켜진 스위치 개수 출력
            cout << query(1, 0, n-1, s-1, t-1) << '\n';
        }
    }
    return 0;
}