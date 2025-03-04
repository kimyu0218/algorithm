#include <iostream>
#include <vector>

using namespace std;

void postorder(int left, int right, vector<int> &nodes) {
    if(left > right) {
        return;
    }

    int idx = right + 1; // root 노드보다 값이 커지는 위치 찾기
    for(int i = left; i <= right; i++) {
        if(nodes[i] > nodes[left]) {
            idx = i;
            break;
        }
    }
    postorder(left+1, idx-1, nodes); // 왼쪽 서브트리
    postorder(idx, right, nodes); // 오른쪽 서브트리
    cout << nodes[left] << '\n';
}

int main() {
    int node;
    vector<int> nodes; // 전위 순회한 결과 저장

    while(cin >> node) {
        nodes.push_back(node);
    }

    postorder(0, nodes.size()-1,  nodes);
    return 0;
}