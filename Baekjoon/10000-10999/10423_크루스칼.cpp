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

int kruskal(vector<tp> &edge) {
    int sum = 0;

    for(auto[w, n1, n2]: edge) {
        if(!unionNodes(n1, n2)) {
            continue;
        }
        sum += w;
    }
    return sum;
}

int main() {
    int n, m, k, u, v, w;
    cin >> n >> m >> k;

    vector<tp> edge;
    parent.assign(n+1, -1);
    vector<int> plant(k, 0);

    for(int i = 0; i < k; i++) { // 발전소가 설치된 도시 입력
        cin >> plant[i];
        for(int j = 0; j < i; j++) { // (발전소끼리 연결될 필요 없음)
            unionNodes(plant[i], plant[j]);
        }
    }

    while(m--) { // 케이블 정보 입력
        cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }
    sort(edge.begin(), edge.end());

    cout << kruskal(edge);
    return 0;
}