#include <iostream>
#include <vector>

using namespace std;

const int INF = 15 * 1e2 + 1;

void floydWarshall(int n, vector<vector<int>> &dist) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int tmp = dist[i][k] + dist[k][j];
                dist[i][j] = min(dist[i][j], tmp);
            }
        }
    }
}

int getItem(int n, int m, vector<int> &item, vector<vector<int>> &dist) {
    int answer = 0;
    for(int i = 1; i <= n; i++) { // i 지역에 낙하
        int sum = 0; // i 지역에 떨어졌을 때 얻을 수 있는 아이템 개수
        for(int j = 1; j <= n; j++) {
            if(dist[i][j] <= m) { // 아이템 습득 가능
                sum += item[j];
            }
        }
        answer = max(answer, sum);
    }
    return answer;
}

int main() {
    int n, m, r, a, b, l;
    vector<int> item;
    vector<vector<int>> dist;

    cin >> n >> m >> r;
    item.assign(n+1, 0);
    dist.assign(n+1, vector<int> (n+1, INF));
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for(int i = 1; i <= n; i++) {
        cin >> item[i];
    }

    while(r--) {
        cin >> a >> b >> l;
        // 양방향 그래프
        dist[a][b] = l;
        dist[b][a] = l;
    }

    floydWarshall(n, dist);
    cout << getItem(n, m, item, dist);
    return 0;
}