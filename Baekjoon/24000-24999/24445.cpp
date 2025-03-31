#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e5;

vector<int> graph[N + 1];

vector<int> bfs(int n, int r) {
    vector<int> answer (n, 0);

    int w = 0;
    queue<int> q;

    q.push(r);
    while(!q.empty()) {
        int v = q.front();
        q.pop();

        if(answer[v - 1]) {
           continue;
        }

        answer[v - 1] = ++w;
        for(int i = 0; i < graph[v].size(); i++) {
            int u = graph[v][i];
            if(!answer[u - 1]) {
                q.push(u);
            }
        }
    }
    return answer;
}

vector<int> solution(int n, int r) {
    for(int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }
    return bfs(n, r);
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