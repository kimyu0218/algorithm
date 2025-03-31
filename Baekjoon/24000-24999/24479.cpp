#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5;

int w = 0;
int visited[N + 1];
vector<int> graph[N + 1];

void dfs(int v) {
    visited[v] = ++w;

    for(int i = 0; i < graph[v].size(); i++) {
        int u = graph[v][i];
        if(!visited[u]) {
            dfs(u);
        }
    }
}

vector<int> solution(int n, int r) {
    vector<int> answer (n, 0);

    for(int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(r);

    for(int i = 1; i <= n; i++) {
        answer[i - 1] = visited[i];
    }
    return answer;
}

int main() {
    int n, m, r, u, v;

    cin >> n >> m >> r;
    while(m--) {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> answer = solution(n, r);

    for(int i = 0; i < n; i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}