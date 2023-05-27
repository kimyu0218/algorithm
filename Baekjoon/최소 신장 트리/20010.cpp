#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
vector<int> parent;
vector<vector<pi>> graph; // 사이클이 형성되지 않는 트리 정보 저장

int findParent(int node) { // find 연산
    if(parent[node] < 0) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

bool unionInput(int x, int y) { // union 연산
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) { // 사이클이 만들어지는 경우
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

int kruskal(priority_queue<ti, vector<ti>, greater<>> &pq) {
    int sum = 0;
    while(!pq.empty()) {
        int c = get<0>(pq.top());
        int a = get<1>(pq.top());
        int b = get<2>(pq.top());
        pq.pop();

        if(unionInput(a, b)) { // a마을과 b마을을 연결할 수 있는 경우
            sum += c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
    }
    return sum;
}

vector<int> bfs(int n, int start) {
    vector<int> dist (n, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int d = graph[node][i].second;
            if(dist[next_node] == -1) {
                dist[next_node] = dist[node] + d;
                q.push(next_node);
            }
        }
    }
    return dist;
}

int furthestRoute(int n) {
    int d, end_point = 0;
    vector<int> dist;

    d = 0;
    dist = bfs(n, 0);
    for(int i = 0; i < n; i++) {
        if(dist[i] > d) {
            d = dist[i];
            end_point = i;
        }
    }

    d = 0;
    dist = bfs(n, end_point);
    for(int i = 0; i < n; i++) {
        d = max(d, dist[i]);
    }
    return d;
}

int main() {
    int n, k, a, b, c;
    priority_queue<ti, vector<ti>, greater<>> pq;

    cin >> n >> k;
    parent.assign(n, -1);
    graph.assign(n, vector<pi> (0));
    while(k--) {
        cin >> a >> b >> c;
        pq.push({c, a, b});
    }

    cout << kruskal(pq) << '\n';
    cout << furthestRoute(n);
    return 0;
}