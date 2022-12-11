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

bool unionNodes(int x, int y) {
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

int kruskal(int m, vector<tp> edge) {
    int sum = 0, cnt = 0;

    for(auto[w, n1, n2]: edge) {
        if(!unionNodes(n1, n2)) { // 사이클 발생
            continue;
        }
        //cout << n1 << " -> " << n2 << '\t' << w << '\n';
        sum += w;
        cnt++;

        if(cnt == m-1) { // 간선 다 찾음
            return sum;
        }
    }
    return sum;
}

int main() {
    int m, n, x, y, z;

    while(true) {
        cin >> m >> n;
        if(m == 0 && n == 0) { // 종료 조건
            break;
        }

        vector<tp> edge;
        parent.assign(m, -1);

        int sum = 0; // 비용의 합
        while(n--) { // 길 정보 입력
            cin >> x >> y >> z;
            sum += z;
            edge.push_back({z, x, y});
        }
        sort(edge.begin(), edge.end());

        int mst = kruskal(m, edge); // 최소 비용
        cout << sum - mst << '\n';
    }
    return 0;
}