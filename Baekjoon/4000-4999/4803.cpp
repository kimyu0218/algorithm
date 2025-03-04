#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; // 루트 정점 저장
vector<bool> cycle; // 사이클 생성 여부

void printResult(int tc, int cnt) { // 결과 출력 함수
    cout << "Case " << tc << ": ";
    switch(cnt) {
        case 0:
            cout << "No trees.\n";
            break;
        case 1:
            cout << "There is one tree.\n";
            break;
        default:
            cout << "A forest of " << cnt << " trees.\n";
            break;
    }
}

int cntTree(int n) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        // 루트 정점이고 사이클이 없는 경우
        if(parent[i] < 0 && !cycle[i]) {
            cnt++;
        }
    }
    return cnt;
}

int findParent(int node) { // find 연산 : node의 루트 노드 반환
    if(parent[node] < 0) { // 루트 노드
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) { // union 연산
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) { // 이미 같은 집합인 경우 -> 사이클 발생
        cycle[xp] = cycle[yp] = true;
        return;
    }

    if(cycle[xp] || cycle[yp]) { // 서로 다른 집합이지만 하나라도 사이클이 있는 경우
        cycle[xp] = cycle[yp] = true;
    }
    if(parent[xp] < parent[yp]) { // 새로운 루트 : xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else { // 새로운 루트 : yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, a, b, tc = 0;

    while(cin >> n >> m) {
        if(n == 0 && m == 0) { // 종료 조건
            break;
        }

        tc++;
        parent.assign(n+1, -1); // 초기화
        cycle.assign(n+1, false);

        while(m--) {
            cin >> a >> b;
            unionInput(a, b);
        }
        printResult(tc, cntTree(n));
    }
    return 0;
}