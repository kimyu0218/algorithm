#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> parent; // 루트 정점 저장

int findParent(int node) { // find 연산
    if(parent[node] < 0) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) { // union 연산
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) { // 이미 같은 집합에 속한 경우
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

int cntFriends(int idx) { // 친구 수 세기
    int p = findParent(idx);
    return abs(parent[p]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, f;
    string id1, id2;

    cin >> t;
    while(t--) { // 테스트 케이스
        cin >> f;

        parent.assign(2*f+1, -1);
        map<string, int> m; // (아이디, 인덱스) 매칭
        int idx = 0;

        for(int i = 0; i < f; i++) {
            cin >> id1 >> id2;

            // 맵에 없는 사람인 경우 인덱스 할당
            if(m[id1] == 0) {
                m[id1] = ++idx;
            }
            if(m[id2] == 0) {
                m[id2] = ++idx;
            }

            unionInput(m[id1], m[id2]);
            cout << cntFriends(m[id1]) << '\n';
        }
    }
    return 0;
}