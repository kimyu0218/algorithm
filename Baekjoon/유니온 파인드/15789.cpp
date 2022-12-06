#include <iostream>
#include <vector>
#include <queue>

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

int maxPower(int c, int h, int n, int k) { // ctp 왕국의 힘의 최댓값
    int cp = findParent(c); // ctp 왕국 집합
    int hp = findParent(h); // 한솔 왕국 집합

    vector<bool> pushed (n+1, false);
    priority_queue<int> pq; // (top이 가장 큰 동맹 왕국을 가리킴)
    for(int i = 1; i <= n; i++) {
        int p = findParent(i);
        if(p != cp && p != hp && !pushed[p]) { // ctp 왕국이나 한솔 왕국이 속한 집합 제외, 이미 포함된 집합 제외
            pq.push(abs(parent[p]));
            pushed[p] = true;
        }
    }

    int power = abs(parent[cp]); // ctp 왕국 자체의 힘
    while(k--) { // 동맹 체결
        power += pq.top();
        pq.pop();
    }
    return power;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, x, y, c, h, k;
    cin >> n >> m;

    parent.assign(n+1, -1); // 초기화
    while(m--) { // 동맹 관계 입력
        cin >> x >> y;
        unionInput(x, y);
    }

    cin >> c >> h >> k; // (ctp 왕국 : c / 한솔 왕국 : h)
    cout << maxPower(c, h, n, k);
}