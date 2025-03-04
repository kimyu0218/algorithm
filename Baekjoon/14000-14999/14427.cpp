#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> pi;
vector<pi> tree; // segment tree

void init(vector<int> &a, int node, int start, int end) {
    if(start == end) { // 리프 노드인 경우
        tree[node] = {a[start], start};
    }
    else { // 리프 노드가 아닌 경우
        int mid = (start + end) / 2;
        init(a, node*2, start, mid);
        init(a, node*2+1, mid+1, end);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

void update(int node, int start, int end, int index, int val) {
    if(index > end || index < start) {
        return;
    }
    if(start == end) {
        tree[node] = {val, index};
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, index, val);
    update(node*2+1, mid+1, end, index, val);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, option, i, v, h, tree_size;
    vector<int> a;

    cin >> n;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));

    a.assign(n, 0);
    tree.assign(tree_size, {0, 0});
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a, 1, 0, n-1);

    cin >> m;
    while(m--) {
        cin >> option;
        if(option == 1) { // 1 i v : i번째 수 v로 변경
            cin >> i >> v;
            update(1, 0, n-1, i-1, v);
        }
        else if(option == 2) { // 2 : 수열의 최솟값 인덱스 출력
            // 인덱스는 0부터 시작하므로 항상 +1
            cout << tree[1].second+1 << '\n';
        }
    }
    return 0;
}