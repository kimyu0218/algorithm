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
    return 0; // mst를 만들 수 없는 경우
}

vector<int> mstGame(int n, int k, vector<tp> &edge) { // mst 게임 실행
    vector<int> result(k, 0); // 턴 결과 저장
    for(int i = 0; i < k; i++) {
        parent.assign(n+1, -1); // 초기화
        result[i] = kruskal(n, edge); // i번째 턴 결과 저장
        edge.erase(edge.begin()); // i턴 종료 후 가중치가 가장 작은 간선 제거
    }
    return result;
}

int main() {
    int n, m, k, x, y;
    cin >> n >> m >> k;

    vector<tp> edge;

    for(int i = 1; i <= m; i++) { // 간선 정보 입력
        cin >> x >> y;
        edge.push_back({i, x, y});
    }
    sort(edge.begin(), edge.end());

    vector<int> result = mstGame(n, k, edge);
    for(int i = 0; i < k; i++) { // 결과 출력
        cout << result[i] << ' ';
    }
    return 0;
}