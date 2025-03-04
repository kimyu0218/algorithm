#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
typedef tuple<double, int, int> tp;
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

double kruskal(int n, vector<tp> &edge) {
    double sum = 0;
    int cnt = 0;

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
    int n, m, x, y, n1, n2, linked = 0;
    cin >> n >> m;

    parent.assign(n+1, -1);
    vector<tp> edge;
    vector<pi> star; // 별 위치

    for(int i = 0; i < n; i++) { // 황선자 + 우주신 좌표 입력
        cin >> x >> y;
        for(int j = 0; j < i; j++) { // 임의의 두 별에 대한 거리
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            edge.push_back({sqrt(dx*dx + dy*dy), i, j});
        }
        star.push_back({x, y});
    }

    while(m--) { // 이미 연결된 통로 입력
        cin >> n1 >> n2;
        linked += unionNodes(n1-1, n2-1); // (이미 연결된 통로 제외)
    }
    sort(edge.begin(), edge.end());

    cout << fixed;
    cout.precision(2); // 소수점 둘째자리까지
    cout << kruskal(n-linked, edge);
    return 0;
}