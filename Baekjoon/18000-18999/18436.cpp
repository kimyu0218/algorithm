#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
vector<ll> odd_tree, even_tree;

void init(vector<int> &a, int node, int start, int end) {
    if(start == end) { // 리프 노드인 경우
        odd_tree[node] = a[start] % 2;
        even_tree[node] = (a[start] % 2 == 0);
    }
    else { // 리프 노드가 아닌 경우
        int mid = (start + end) / 2;
        init(a, node*2, start, mid);
        init(a, node*2+1, mid+1, end);
        odd_tree[node] = odd_tree[node*2] + odd_tree[node*2+1];
        even_tree[node] = even_tree[node*2] + even_tree[node*2+1];
    }
}

void update(int node, int start, int end, int index, int val) {
    if(index > end || index < start) {
        return;
    }
    if(start == end) {
        odd_tree[node] = val % 2;
        even_tree[node] = (val % 2 == 0);
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, index, val);
    update(node*2+1, mid+1, end, index, val);
    odd_tree[node] = odd_tree[node*2] + odd_tree[node*2+1];
    even_tree[node] = even_tree[node*2] + even_tree[node*2+1];
}

ll query(int node, int start, int end, int left, int right, int option) {
    if(left > end || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        if(option == 2) { // option이 2인 경우, 짝수 개수 리턴
            return even_tree[node];
        }
        return odd_tree[node]; // option이 3인 경우, 홀수 개수 리턴
    }
    int mid = (start + end) / 2;
    ll lsum = query(node*2, start, mid, left, right, option);
    ll rsum = query(node*2+1, mid+1, end, left, right, option);
    return lsum + rsum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, option, l, r, h, tree_size;
    vector<int> a;

    cin >> n;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));

    a.assign(n, 0);
    odd_tree.assign(tree_size, 0);
    even_tree.assign(tree_size, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a, 1, 0, n-1);

    cin >> m;
    while(m--) {
        cin >> option >> l >> r;
        if(option == 1) { // 1 i x : i번째 수 x로 변경
            update(1, 0, n-1, l-1, r);
        }
        else if(option == 2) { // 2 l r : 짝수 개수 출력
            cout << query(1, 0, n-1, l-1, r-1, option) << '\n';
        }
        else if(option == 3) { // 3 l r : 홀수 개수 출력
            cout << query(1, 0, n-1, l-1, r-1, option) << '\n';
        }
    }
    return 0;
}