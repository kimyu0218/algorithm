#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> tp;
vector<int> parent;

int findParent(int node) { // find 연산
    if(parent[node] < 0) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

bool unionNodes(int x, int y) { // union 연산
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) { // 사이클 발생
        return false;
    }
    if(parent[xp] < parent[yp]) {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

int kruskal(int n, vector<tp> &edge) {
    int sum = 0, cnt = 0;

    for(auto[w, n1, n2]: edge) {
        if(!unionNodes(n1, n2)) { // 사이클 발생
            continue;
        }
        sum += w;
        cnt++;

        if(cnt == n-1) { // 간선 다 찾음 (== 모든 도시가 연결된 상태)
            // 하나의 간선만 끊어도 도시 2개로 분리
            return sum-w; // (마지막 간선이 제일 큰 비용)
        }
    }
    return 0; // mst 만들 수 없음
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;

    vector<tp> edge;
    parent.assign(n+1, -1); // 초기화

    while(m--) { // 간선 정보 입력
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());

    cout << kruskal(n, edge);
    return 0;
}