#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; // 루트 정점 저장
vector<bool> truth; // 진실 여부

int findParent(int node) { // find 연산 : node의 루트 노드 반환
    if(parent[node] < 0) { // 루트 노드
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) { // union 연산
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) { // 이미 같은 집합인 경우
        return;
    }
    if(truth[xp] || truth[yp]) { // 둘 중 하나라도 진실을 믿는 경우
        truth[xp] = truth[yp] = true;
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

int exaggerate(vector<int> mems) { // 과장할 수 있는 파티 개수 반환
    int cnt = 0; // 파티 개수
    for(int i = 0; i < mems.size(); i++) {
        int root = findParent(mems[i]);
        if(!truth[root]) { // 진실 여부 모름
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, cnt, mem;
    vector<int> mems; // 첫번째 파티원 저장

    cin >> n >> m;
    parent.assign(n+1, -1); // 초기화
    truth.assign(n+1, false);

    cin >> cnt;
    while(cnt--) { // 진실 세팅
        cin >> mem;
        truth[mem] = true;
    }

    int first_mem;
    while(m--) {
        cin >> cnt >> first_mem; // 파티 인원, 첫번째 파티원

        mems.push_back(first_mem);
        while(--cnt) { // union 연산
            cin >> mem;
            unionInput(first_mem, mem);
        }
    }

    cout << exaggerate(mems);
    return 0;
}