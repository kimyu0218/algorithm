#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e7 + 1;
struct info {
    int dist; // 도시 i에서 도시 j로 가는데 필요한 최소 비용
    queue<int> route; // 도시 i에서 도시 j로 가는 경로
};

void floydWarshall(int n, vector<vector<info>> &dist) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int tmp = dist[i][k].dist + dist[k][j].dist;
                if(tmp < dist[i][j].dist) {
                    dist[i][j].dist = tmp;
                    dist[i][j].route = dist[i][k].route; // i부터 k까지의 route
                    queue<int> q = dist[k][j].route;
                    q.pop(); // k 제거
                    while(!q.empty()) { // k 제외 j까지의 route 추가
                        dist[i][j].route.push(q.front());
                        q.pop();
                    }
                }
            }
        }
    }
}

void printCost(int n, vector<vector<info>> &dist) { // 최소 비용 출력
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dist[i][j].dist >= INF) { // i에서 j로 갈 수 없는 경우, 0 출력
                cout << 0 << ' ';
            }
            else { // 최소 비용 출력
                cout << dist[i][j].dist << ' ';
            }
        }
        cout << '\n';
    }
}

void printRoute(int n, vector<vector<info>> &dist) { // 경로 출력
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << dist[i][j].route.size() << ' '; // 경로에 포함된 도시의 개수
            while(!dist[i][j].route.empty()) { // 경로 출력
                cout << dist[i][j].route.front() << ' ';
                dist[i][j].route.pop();
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, a, b, c;
    vector<vector<info>> dist;

    cin >> n;
    dist.assign(n+1, vector<info> (n+1, {INF, queue<int> ()}));
    for(int i = 1; i <= n; i++) { // 초기화
        dist[i][i].dist = 0;
    }

    cin >> m;
    while(m--) { // 버스 정보 입력
        cin >> a >> b >> c;
        if(dist[a][b].route.empty()) { // 경로 추가
            dist[a][b].route.push(a);
            dist[a][b].route.push(b);
        }
        if(c < dist[a][b].dist) { // 최소 비용 갱신
            dist[a][b].dist = c;
        }
    }
    
    floydWarshall(n, dist);
    printCost(n, dist); // 최소 비용 출력
    printRoute(n, dist); // 경로 출력
    return 0;
}