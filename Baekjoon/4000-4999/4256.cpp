#include <iostream>
#include <vector>

using namespace std;

// 1. 전위 순회 : 루트의 위치는 알 수 있지만 서브 트리의 경계 알 수 없음
// 2. 중위 순회 : 루트를 중심으로 왼쪽, 오른쪽 서브 트리가 나뉨
vector<int> preorder, inorder_idx;

void divide(int idx, int left, int right) { // (idx : 루트 위치)
    if(left > right) return; // conquer
    int root = preorder[idx];
    int root_idx = inorder_idx[root]; // 루트 위치 파악 -> 중위 순회로 서브 트리 분할

    // 후위 순회 : 왼쪽 -> 오른쪽 -> 루트
    // divide
    divide(idx + 1, left, root_idx - 1); // 왼쪽 서브 트리 (idx + 1 == 왼쪽 서브 트리 루트)
    divide(idx + 1 + (root_idx - left), root_idx + 1, right); // 오른쪽 서브 트리
    cout << root << ' ';
}

int main() {
    int t, n, num;
    cin >> t;

    while(t--) {
        cin >> n;
        preorder.assign(n, 0);
        inorder_idx.assign(n+1, 0);

        for(int i = 0; i < n; i++) // 전위 순회 입력
            cin >> preorder[i];

        for(int i = 0; i < n; i++) { // 중위 순회 입력
            cin >> num;
            inorder_idx[num] = i;
        }

        divide(0, 0, n-1);
        cout << '\n';
    }
    return 0;
}