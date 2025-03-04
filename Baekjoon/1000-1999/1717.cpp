#include <iostream>
#include <vector>

using namespace std;

// Weighted Union Find
// 음수 : 루트 정점, 절댓값 == 집합의 크기
// 양수 : 루트 정점 저장
vector<int> parent; // 루트 노드 저장

int findParent(int node) { // find 연산 : 루트 노드 반환
    if(parent[node] < 0) { // 루트 노드인 경우
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
    int xp = findParent(x); // x의 루트 노드
    int yp = findParent(y); // y의 루트 노드

    if(xp == yp) { // 이미 같은 집합에 있는 경우 (루트 노드가 서로 같은 경우)
        return;
    }
    if(parent[xp] < parent[yp]) { // 새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else { // 새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, cmd, a, b;
    cin >> n >> m;

    parent.assign(n+1, -1); // parent 벡터 초기화
    while(m--) {
        cin >> cmd >> a >> b;

        if(!cmd) { // union 연산
            unionInput(a, b);
        }
        else { // find 연산
            if(findParent(a) == findParent(b)) {
                cout << "YES\n";
            }
            else {
                 cout << "NO\n";
            }
        }
    }
    return 0;
}