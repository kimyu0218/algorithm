#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; // 루트 정점

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

vector<int> linkBridge(int n) { // 다리 연결하기
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(parent[i] < 0) { // 연결할 정점 발견
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    int n, x, y;
    cin >> n;

    parent.assign(n+1, -1); // 초기화
    for(int i = 0; i < n-2; i++) {
        cin >> x >> y;
        unionInput(x, y);
    }

    vector<int> ans = linkBridge(n);
    cout << ans[0] << ' ' << ans[1];
    return 0;
}