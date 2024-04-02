#include <string>
#include <vector>

using namespace std;

void dfs(int num, int n, vector<bool> &visited, vector<vector<int>> computers) {
    visited[num] = true;

    for(int i = 0; i < n; i++) {
        if(visited[i] || !computers[num][i]) {
            continue;
        }
        dfs(i, n, visited, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++) {
        if(visited[i]) {
            continue;
        }
        dfs(i, n, visited, computers);
        answer++;
    }
    return answer;
}