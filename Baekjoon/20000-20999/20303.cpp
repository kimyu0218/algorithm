#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node) { // find 연산
    if(parent[node] < 0) { // 루트 정점
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

int maxCandy(int n, int k, vector<int> c) { // 최대 사탕 수 세기
    vector<int> candy (n+1, 0); // candy[i] == i집합의 최대 사탕 수

    for(int i = 1; i <= n; i++) { // 집합의 총 사탕 수 구하기
        int p = findParent(i); // 아이(i)가 속한 집합의 루트 정점(p)
        candy[p] += c[i]; // p 집합에 아이의 사탕 수 더하기
    }

    vector<int> dp (k, 0); // dp[i] == i명일 때 최대 사탕 수
    for(int i = 1; i <= n; i++) {
        if(candy[i] == 0) { continue; } // (원소가 0개인 집합 pass)
        int child = abs(parent[i]); // i 집합에 속한 아이들 수
        if(child > k) { continue; } // (k명 이상인 경우 pass)

        for(int j = k-1; j >= child; j--) { // knapsack
            dp[j] = max(dp[j], candy[i] + dp[j-child]);
        }
    }
    return dp[k-1];
}

int main() {
    int n, m, k, a, b;
    cin >> n >> m >> k;

    parent.assign(n+1, -1); // 초기화

    vector<int> c (n+1, 0); // 아이들이 받은 사탕 수
    for(int i = 1; i <= n; i++) { // 사탕 수 입력
        cin >> c[i];
    }

    while(m--) {
        cin >> a >> b;
        unionInput(a, b);
    }

    cout << maxCandy(n, k, c);
    return 0;
}