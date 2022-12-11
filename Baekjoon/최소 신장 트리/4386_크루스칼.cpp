#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<double, double> pd;
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

    if(xp == yp) { // 이미 같은 집합에 속한 경우 (== 사이클 생성)
        return false;
    }
    if(parent[xp] < parent[yp]) { // 새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else { // 새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

double kruskal(int n, vector<tp> edge) {
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
    int n;
    double x, y;
    cin >> n;

    parent.assign(n, -1);
    vector<tp> edge; // 간선 배열
    vector<pd> star; // 별 위치

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        for(int j = 0; j < i; j++) { // 임의의 두 별에 대한 거리 구하기
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            edge.push_back({sqrt(dx*dx + dy*dy), i, j});
        }
        star.push_back({x, y});
    }
    sort(edge.begin(), edge.end());

    cout << fixed; // 고정된 소수점
    cout.precision(2); // 소수점 둘째자리까지
    cout << kruskal(n, edge);
    return 0;
}