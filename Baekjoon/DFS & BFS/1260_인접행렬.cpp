#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void dfs(int n, int v, vector<vector<int>> adj_matrix) {
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

        for(int i = n - 1; i >= 0; i--) {
            if(visited[i] || !adj_matrix[node][i]) {
                continue;
            }
            s.push(i);
        }
    }
}

void bfs(int n, int v, vector<vector<int>> adj_matrix) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(v - 1);
    visited[v - 1] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node + 1 << ' ';

        for(int i = 0; i < n; i++) {
            if(visited[i] || !adj_matrix[node][i]) {
                continue;
            }
            visited[i] = true;
            q.push(i);
        }
    }
}

void solution(int n, int v, vector<vector<int>> adj_matrix) {
    dfs(n, v, adj_matrix);
    cout << '\n';
    bfs(n, v, adj_matrix);
}

int main() {
    int n, m, v, a, b;
    vector<vector<int>> adj_matrix;

    cin >> n >> m >> v;

    adj_matrix.assign(n, vector<int> (n, 0));
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj_matrix[a - 1][b - 1] = adj_matrix[b - 1][a - 1] = true;
    }

    solution(n, v, adj_matrix);
    return 0;
}