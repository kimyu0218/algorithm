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

int main() {
    int n, m, link, city;
    cin >> n >> m;

    parent.assign(n+1, -1); // 초기화
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> link;
            if(link) { // link == 1인 경우, i와 j 도시 연결
                unionInput(i, j);
            }
        }
    }

    cin >> city;
    int course = findParent(city); // 첫번째 도시의 집합 저장
    string result = "YES"; // 출력할 결과 저장
    while(--m) {
        cin >> city;
        int tmp = findParent(city); // 첫번째 도시와 같은 집합에 포함되었는가
        if(tmp != course) {
            result = "NO";
        }
    }

    cout << result;
    return 0;
}