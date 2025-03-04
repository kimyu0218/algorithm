#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e6;
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

int cntPart(int c) { // 부품 개수 세기
    int cp = findParent(c);
    return abs(parent[cp]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, a, b, c;
    char cmd;
    cin >> n;

    parent.assign(MAX+1, -1);
    while(n--) { // 지시 시작
        cin >> cmd;
        if(cmd == 'I') { // 두 부품은 같은 로봇의 부품이다
            cin >> a >> b;
            unionInput(a, b);
        }
        else if(cmd == 'Q') { // 로봇의 부품이 몇 개인가
            cin >> c;
            cout << cntPart(c) << '\n';
        }
    }
    return 0;
}