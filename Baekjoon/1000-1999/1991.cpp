#include <iostream>
#include <map>

using namespace std;

//(key: 부모 노드, value: 왼쪽 자식 노드, 오른쪽 자식 노드)
map<char, pair<char, char>> tree;

void preorder(char node) { // 전위 순회 : 루트 -> 왼쪽 자식 -> 오른쪽 자식
    if(node == '.') return;
    cout << node;
    preorder(tree[node].first);
    preorder(tree[node].second);
}

void inorder(char node) { // 중위 순회 : 왼쪽 자식 -> 루트 -> 오른쪽 자식
    if(node == '.') return;
    inorder(tree[node].first);
    cout << node;
    inorder(tree[node].second);
}

void postorder(char node) { // 후위 순회 : 왼쪽 자식 -> 오른쪽 자식 -> 루트
    if(node == '.') return;
    postorder(tree[node].first);
    postorder(tree[node].second);
    cout << node;
}

int main() {
    int n;
    cin >> n;

    char node, left, right;
    while(n--) {
        cin >> node >> left >> right;
        tree[node] = {left, right};
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}