#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 1e6 + 1;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
vector<int> parent;

int findParent(int node) { // find 연산
    if(parent[node] < 0) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

bool unionInput(int x, int y) { // union 연산
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) { // 사이클이 생성되는 경우
        return false;
    }
    if(parent[xp] < parent[yp]) {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

vector<vector<pi>> kruskal(int n, priority_queue<ti> &pq) { // 가중치가 가장 큰 그래프 만들기
    vector<vector<pi>> graph (n+1, vector<pi> (0));
    while(!pq.empty()) {
        int k = get<0>(pq.top());
        int h1 = get<1>(pq.top());
        int h2 = get<2>(pq.top());
        pq.pop();

        if(unionInput(h1, h2)) {
            graph[h1].push_back({h2, k});
            graph[h2].push_back({h1, k});
        }
    }
    return graph;
}

int bfs(int n, int s, int e, priority_queue<ti> &pq) {
    vector<vector<pi>> graph = kruskal(n, pq);
    vector<int> visited (n+1, INF);

    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int h1 = q.front();
        q.pop();

        if(h1 == e) {
            break;
        }

        for(int i = 0; i < graph[h1].size(); i++) {
            int h2 = graph[h1][i].first;
            int k = graph[h1][i].second;
            if(visited[h2] == INF) {
                visited[h2] = min(k, visited[h1]);
                q.push(h2);
            }
        }
    }
    return visited[e]; // s부터 e까지 들고갈 수 있는 금빼빼로 최대 개수
}

int main() {
    int n, m, s, e, h1, h2, k;
    priority_queue<ti> pq;

    cin >> n >> m;
    cin >> s >> e;
    parent.assign(n+1, -1);
    while(m--) { // 다리 정보 입력
        cin >> h1 >> h2 >> k;
        // h1에서 h2까지 가는 다리의 무게 제한 k
        pq.push({k, h1, h2});
    }

    int answer = bfs(n, s, e, pq);
    if(answer == INF) { // 빼빼로 가져갈 수 없는 경우
        cout << 0;
    }
    else { // 빼빼로 가져갈 수 있는 경우
        cout << answer;
    }
    return 0;
}