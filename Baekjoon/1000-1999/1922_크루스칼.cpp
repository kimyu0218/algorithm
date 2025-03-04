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

    if(xp == yp) {
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

        if(cnt == n-1) { // 간선 다 찾음
            return sum;
        }
    }
    return sum;
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;

    vector<tp> edge;
    parent.assign(n+1, -1);

    while(m--) { // 컴퓨터 연결 비용
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());

    cout << kruskal(n, edge);
    return 0;
}