#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<double, double> pd;
typedef pair<double, int> pdi;
const int INF = 1e5;

double prim(int n, int start, vector<vector<pdi>> graph) {
    double sum = 0;
    priority_queue<pdi, vector<pdi>, greater<>> pq;
    vector<bool> visited(n, false);
    vector<double> dist(n, INF);

    dist[start] = 0; // 시작점
    pq.push({0, start});

    while(!pq.empty()) {
        auto[curr_w, curr] = pq.top(); pq.pop();

        if(visited[curr]) { // 이미 방문한 정점인가
            continue;
        }
        visited[curr] = true;
        sum += curr_w;

        for(auto[next_w, next]: graph[curr]) {
            // 미방문 정점이고 더 짧은 가중치 발견
            if(!visited[next] && next_w < dist[next]) {
                pq.push({next_w, next});
                dist[next] = next_w;
            }
        }
    }
    return sum;
}

int main() {
    int n;
    double x, y;
    cin >> n;

    vector<pd> star;
    vector<vector<pdi>> graph(n, vector<pdi>(0));

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        for(int j = 0; j < i; j++) {
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            double dist = sqrt(dx*dx + dy*dy);

            graph[i].push_back({dist, j});
            graph[j].push_back({dist, i});
        }
        star.push_back({x, y});
    }

    cout << fixed; // 고정된 소수점
    cout.precision(2); // 소수점 둘째자리까지
    cout << prim(n, 0, graph);
    return 0;
}