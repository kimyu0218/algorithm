#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node) { // find 연산
    if(parent[node] < 0) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) { // union 연산
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) {
        return;
    }
    if(parent[xp] < parent[yp]) { // 새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else { // 새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

bool isLinked(int x, int y) { // 경로 존재 여부 반환
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n, k, a, b, m, u, v;
    cin >> t;

    for(int i = 1; i <= t; i++) { // 테스트 케이스
        cin >> n >> k;

        parent.assign(n+1, -1); // 초기화
        for(int j = 0; j < k; j++) { // 친구 관계 입력
            cin >> a >> b;
            unionInput(a, b);
        }

        cout << "Scenario " << i << ":\n"; // 테스트 케이스 결과 출력 시작
        cin >> m;
        for(int j = 0; j < m; j++) {
            cin >> u >> v;
            cout << isLinked(u, v) << '\n';
        }
        cout << '\n'; // 테스트 케이스 결과 출력 끝
    }
    return 0;
}