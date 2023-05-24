#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
vector<ll> tree; // segment tree

void init(vector<int> &arr, int node, int start, int end) {
    // 1. 리프 노드 : 배열의 수 그 자체
    if(start == end) {
        tree[node] = arr[start];
    }
    // 2. 리프 노드가 아닌 노드 : 왼쪽 자식과 오른쪽 자식의 합
    else {
        // 2 * node : 왼쪽 자식 / 2 * node + 1 : 오른쪽 자식
        int mid = (start + end) / 2;
        init(arr, node*2, start, mid); // 왼쪽 서브트리
        init(arr, node*2+1, mid+1, end); // 오른쪽 서브트리
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll query(int node, int start, int end, int left, int right) {
    // 1. left > end : [start, end] [left, right]
    // 2. right < start : [left, right] [start, end]
    if(left > end || right < start) { // 더 이상 탐색할 필요가 없음
        return 0;
    }
    // [left, start, end, right]
    if(left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    ll lsum = query(node*2, start, mid, left, right);
    ll rsum = query(node*2+1, mid+1, end, left, right);
    return lsum + rsum;
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

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q, x, y, a, b, h, tree_size;
    vector<int> arr;

    cin >> n >> q;
    h = (int) ceil(log2(n));
    tree_size = (1 << (h+1));

    arr.assign(n, 0);
    tree.assign(tree_size, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(arr, 1, 0, n-1);

    while(q--) {
        cin >> x >> y >> a >> b;
        // 1. x ~ y 구간합 출력
        if(x > y) { // x가 y보다 큰 경우, swap
            swap(x, y);
        }
        cout << query(1, 0, n-1, x-1, y-1) << '\n';

        // 2. a번째 수 b로 변경
        ll diff = (ll) b - (ll) arr[a-1];
        arr[a-1] = b;
        update(1, 0, n-1, a-1, diff);
    }
    return 0;
}