#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

bool cmp(vector<int> &v1, vector<int> &v2) {
    return v1[2] < v2[2];
}

void connect(int a, int b, int n, vector<vector<bool>> &connected) {
    queue<pi> q;
    q.push({a, b});

    while(!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        for(int i = 0; i < n; i++) {
            if(connected[u][i] && !connected[v][i]) {
                connected[v][i] = connected[i][v] = true;
                q.push({v, i});
            }
            if(connected[v][i] && !connected[u][i]) {
                connected[u][i] = connected[i][u] = true;
                q.push({u, i});
            }
        }
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmp);

    vector<vector<bool>> connected(n, vector<bool> (n, false));
    for(int i = 0; i < n; i++) {
        connected[i][i] = true;
    }

    for(int i = 0; i < costs.size(); i++) {
        int a = costs[i][0];
        int b = costs[i][1];
        int w = costs[i][2];

        if(connected[a][b]) {
            continue;
        }
        connected[a][b] = connected[b][a] = true;
        answer += w;

        connect(a, b, n, connected);
    }
    return answer;
}