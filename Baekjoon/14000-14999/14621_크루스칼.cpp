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

int kruskal(int n, vector<char> type, vector<tp> &edge) {
    int sum = 0, cnt = 0, idx = 0;

    while(true) {
        if(idx >= edge.size()) { // idx가 edge 범위를 벗어난 경우
            break;
        }

        auto[w, n1, n2] = edge[idx];
        // 1. 서로 같은 종류 대학 pass
        // 2. 사이클 발생한 경우 pass
        if(type[n1] == type[n2]|| !unionNodes(n1, n2)) {
            idx++;
            continue;
        }

        sum += w;
        edge.erase(edge.begin()+idx); // idx번째 경로 이용
        cnt++; idx = 0;

        if(cnt == n-1) { // 간선 다 찾음
            return sum;
        }
    }
    return -1; // mst 만들 수 없는 경우
}

int main() {
    int n, m, u, v, d;
    cin >> n >> m;

    parent.assign(n+1, -1);
    vector<char> type(n+1, '\0');
    vector<tp> edge;

    for(int i = 1; i <= n; i++) { // 대학교 종류 입력
        cin >> type[i];
    }

    while(m--) { // 도로 정보 입력
        cin >> u >> v >> d;
        edge.push_back({d, u, v});
    }
    sort(edge.begin(), edge.end());

    cout << kruskal(n, type, edge);
    return 0;
}