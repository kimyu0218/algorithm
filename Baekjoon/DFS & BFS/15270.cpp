#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 20;

bool visited[SIZE];
vector<vector<int>> relation;

int dfs(int u, int cnt, int n) { // 쌍 만들기
    if(u == n) { // 인덱스 초과
        return cnt;
    }
    if(visited[u]) { // 이미 쌍 만든 경우 pass
        return dfs(u+1, cnt, n);
    }
    int result = 0;
    visited[u] = true; // u 줄 세우기
    for(int i = 0; i < relation[u].size(); i++) {
        int v = relation[u][i]; // u의 친한 친구
        if(!visited[v]) { // v가 아직 줄 서지 않은 경우
            visited[v] = true; // v 줄 세우기
            result = max(result, dfs(u+1, cnt+1, n));
            visited[v] = false; // v 줄 세우기 취소
        }
    }
    visited[u] = false; // u 줄 세우기 취소
    return max(result, dfs(u+1, cnt, n));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, u, v;

    cin >> n >> m;
    relation.assign(n, vector<int> (0));
    while(m--) {
        cin >> u >> v;
        if(u > v) {
            swap(u, v);
        }
        relation[u-1].push_back(v-1);
    }

    int answer = dfs(0, 0, n) * 2;
    if(answer < n) { // 로봇댄스 추는 친구 있음
        cout << answer+1;
    }
    else {
        cout << answer;
    }
    return 0;
}