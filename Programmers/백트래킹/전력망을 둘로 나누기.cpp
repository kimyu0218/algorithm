#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

int dfs(int node, int unable, vector<vector<int>> wires) {
    visited[node] = true;

    int result = 1;
    for(int i = 0; i < wires.size(); i++) {
        if(i == unable) {
            continue;
        }

        int u = wires[i][0] - 1;
        int v = wires[i][1] - 1;
        if(u != node && v != node) {
            continue;
        }

        int s = (u == node) ? u : v;
        int e = (u == node) ? v : u;
        if(visited[e]) {
            continue;
        }
        result += dfs(e, unable, wires);
    }
    return result;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for(int i = 0; i < wires.size(); i++) {
        visited.assign(n, false);

        int first = dfs(0, i, wires);
        int second = 0;

        for(int j = 0; j < n; j++) {
            if(visited[j]) {
                continue;
            }
            second = dfs(j, i, wires);
            break;
        }
        if(first + second == n) {
            answer = min(answer, abs(first - second));
        }
    }
    return answer;
}