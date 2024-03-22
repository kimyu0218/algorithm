#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int n, int v, vector<vector<int>> adj_list) {
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(v - 1);

    while(!s.empty()) {
        int node = s.top();
        s.pop();

        if(visited[node]) {
            continue;
        }
        visited[node] = true;
        cout << node + 1 << ' ';

        for(int i = adj_list[node].size() - 1; i >= 0; i--) {
            int next = adj_list[node][i];
            if(visited[next]) {
                continue;
            }
            s.push(next);
        }
    }
}

void bfs(int n, int v, vector<vector<int>> adj_list) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(v - 1);
    visited[v - 1] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node + 1 << ' ';

        for(int i = 0; i < adj_list[node].size(); i++) {
            int next = adj_list[node][i];
            if(visited[next]) {
                continue;
            }
            visited[next] = true;
            q.push(next);
        }
    }
}

void solution(int n, int v, vector<vector<int>> adj_list) {
    for(int i = 0; i < n; i++) {
        sort(adj_list[i].begin(), adj_list[i].end());
    }

    dfs(n, v, adj_list);
    cout << '\n';
    bfs(n, v, adj_list);
}

int main() {
    int n, m, v, a, b;
    vector<vector<int>> adj_list;

    cin >> n >> m >> v;

    adj_list.assign(n, vector<int> (0));
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj_list[a - 1].push_back(b - 1);
        adj_list[b - 1].push_back(a - 1);
    }

    solution(n, v, adj_list);
    return 0;
}