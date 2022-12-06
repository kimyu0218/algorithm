#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node) { // find 연산
    if(parent[node] < 0) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) { // union 연산
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) {
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

int cntConnection(int n) { // 연결 요소 개수 세기
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(parent[i] < 0) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, m, u, v;
    cin >> n >> m;

    parent.assign(n+1, -1);
    while(m--) {
        cin >> u >> v;
        unionInput(u, v);
    }

    cout << cntConnection(n);
    return 0;
}