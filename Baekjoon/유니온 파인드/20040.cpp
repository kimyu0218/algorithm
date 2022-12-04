#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<bool> cycle;

int findParent(int node) { // find 연산
    if(parent[node] < 0) { // 루트 정점
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) { // union 연산
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) { // 이미 같은 집합에 속한 경우 -> 사이클 발생
        cycle[xp] = cycle[yp] = true;
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

    int n, m, x, y, order = 0;
    cin >> n >> m;

    parent.assign(n, -1); // 초기화
    cycle.assign(n, false);

    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        unionInput(x, y);

        if(!order) { // 이전까지 사이클이 없었던 경우
            int xp = findParent(x);
            if(cycle[xp]) { // 사이클 발생한 경우
                order = i; // 사이클이 처음 만들어진 차례 세팅
            }
        }
    }

    cout << order;
    return 0;
}