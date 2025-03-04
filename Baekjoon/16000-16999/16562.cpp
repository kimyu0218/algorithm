#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e4 + 1;

vector<int> parent; // 루트 정점 저장

int findParent(int node) { // find 연산
    if(parent[node] < 0) { // 루트 정점
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) { // union 연산
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) { // 이미 같은 집합에 속한 경우
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

int minCost(int n, vector<int> a) { // 최소 비용 계산하기
    vector<int> costs (n+1, MAX);
    for(int i = 1; i <= n; i++) { // (i: 학생)
        int p = findParent(i); // (i 학생이 속한 집합의 루트 정점)
        if(a[i] < costs[p]) {
            costs[p] = a[i];
        }
    }

    int total = 0;
    for(int i = 1; i <= n; i++) {
        if(costs[i] != MAX) {
            total += costs[i];
        }
    }
    return total;
}

int main() {
    int n, m, k, v, w;
    cin >> n >> m >> k;

    parent.assign(n+1, -1); // parent 초기화
    vector<int> a (n+1, 0); // 친구비 저장

    for(int i = 1; i <= n; i++) {  // 친구비 입력
        cin >> a[i];
    }

    while(m--) { // 친구 관계 입력
        cin >> v >> w;
        unionInput(v, w);
    }

    int cost = minCost(n, a); // 최소 비용
    if(cost > k) { // 친구를 다 사귈 수 없는 경우
        cout << "Oh no";
    }
    else cout << cost;
    return 0;
}