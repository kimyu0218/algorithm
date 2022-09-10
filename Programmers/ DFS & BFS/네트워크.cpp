#include <string>
#include <vector>

using namespace std;

void dfs(int node, int n, vector<bool> &visited, vector<vector<int>> computers) {
    visited[node] = true;
    for(int i = 0; i < n; i++) { // node 컴퓨터와 연결된 다른 컴퓨터 탐색
        if(i == node) continue;
        if(computers[node][i] && !visited[i]) // 아직 방문하지 않은, 연결된 컴퓨터 발견
            dfs(i, n, visited, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited (n, false); // 컴퓨터 방문 여부
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, n, visited, computers);
            answer++;
        }
    }
    return answer;
}