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

int minKruskal(int n, vector<tp> &edge) { // 최적의 경로
    int sum = 0, cnt = 0;

    for(auto[w, n1, n2]: edge) {
        if(!unionNodes(n1, n2)) { // 사이클 생성
            continue;
        }
        sum += (w == 0);
        cnt++;

        if(cnt == n-1) { // 간선 다 찾음
            return sum;
        }
    }
    return sum;
}

int maxKruskal(int n, vector<tp> &edge) { // 최악의 경로
    int sum = 0, cnt = 0;

    for(auto[w, n1, n2]: edge) {
        if(!unionNodes(n1, n2)) { // 사이클 생성
            continue;
        }
        sum += (w == 0);
        cnt++;

        if(cnt == n-1) { // 간선 다 찾음
            return sum;
        }
    }
    return sum;
}

void initialize(int n, int e1, int e2, int option, vector<tp> &edge) { // 최소 신장 트리 전 초기화
    if(option) { // c == 1일 때가 내리막길이므로 내림차순 정렬
        sort(edge.begin(), edge.end(), greater<>());
    }
    else { // c == 0일 때가 오르막길이므로 오름차순 정렬
        sort(edge.begin(), edge.end());
    }
    parent.assign(n+1, -1);
    unionNodes(e1, e2);
}

int diff(int n, int e1, int e2, int entry, vector<tp> &edge) { // 피로도 차이 계산하기
    initialize(n, e1, e2, 1, edge);
    int min = entry + minKruskal(n, edge);

    initialize(n, e1, e2, 0, edge);
    int max = entry + maxKruskal(n, edge);

    return (max*max - min*min);
}

int main() {
    int n, m, a, b, c, e1, e2, w, entry;
    cin >> n >> m;

    vector<tp> edge;

    cin >> e1 >> e2 >> w; // 입구와 도로 연결 관계 입력
    entry = (w == 0);

    while(m--) { // 도로 정보 입력
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }

    cout << diff(n, e1, e2, entry, edge);
    return 0;
}