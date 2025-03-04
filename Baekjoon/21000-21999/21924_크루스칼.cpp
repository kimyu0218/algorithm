#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef long long ll;
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

    if(xp == yp) { // 사이클이 생성되는 경우
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

ll kruskal(int n, vector<tp> &edge) {
    ll sum = 0;
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
    return -1; // mst를 만들 수 없는 경우
}

int main() {
    int n, m, a, b, c;
    ll sum = 0; // 도로를 다 설치할 때 드는 비용
    cin >> n >> m;

    vector<tp> edge;
    parent.assign(n+1, -1);

    while(m--) { // 도로 정보 입력
        cin >> a >> b >> c;
        sum += c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());

    ll money = kruskal(n, edge); // 최소 설치 비용
    if(money == -1) { // 모든 건물이 연결되지 않은 경우
        cout << money;
    }
    else { // 모든 건물이 연결된 경우 절약 비용 출력
        cout << sum-money;
    }
    return 0;
}