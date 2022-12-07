#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int compute(int n, int p1, int p2, vector<vector<int>> graph) { // 촌수 계산하기
    vector<bool> visited (n+1, false); // 방문 여부 체크
    queue<pi> q;
    visited[p1] = true; // p1 방문 체크
    for(int i = 0; i < graph[p1].size(); i++) { // p1의 1촌 push
        q.push({graph[p1][i], 1});
    }

    while(!q.empty()) {
        int node = q.front().first, step = q.front().second; // 사람, 촌수
        q.pop();

        if(visited[node]) { // 이미 방문한 사람 pass
            continue;
        }
        visited[node] = true; // 방문 체크

        if(node == p2) { // 촌수 계산 완료
            return step;
        }
        for(int i = 0; i < graph[node].size(); i++) { // node의 1촌 push
            q.push({graph[node][i], step+1});
        }
    }
    return -1; // 촌수 계산 불가
}

int main() {
    int n, p1, p2, m, x, y;
    cin >> n;
    cin >> p1 >> p2;

    vector<vector<int>> graph (n+1, vector<int> (0)); // 인접 리스트
    cin >> m;
    while(m--) { // 부모 자식 관계 입력
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << compute(n, p1, p2, graph);
    return 0;
}