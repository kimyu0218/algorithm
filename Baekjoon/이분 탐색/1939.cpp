#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

bool bfs(int src, int dst, int k, int n, vector<vector<pi>> &edge) { // k 중량을 src에서 dst로 옮길 수 있는가
    queue<int> q;
    vector<bool> visited (n+1, false);

    // 시작 정점 세팅
    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        if(node == dst) { // 도착점에 도착한 경우
            return true;
        }

        for(int i = 0; i < edge[node].size(); i++) { // 인접 정점 탐색
            int next = edge[node][i].first;
            int w = edge[node][i].second;

            if(!visited[next] && w >= k) { // 아직 방문하지 않은 정점이고 k 중량을 옮길 수 있는 경우
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int binarySearch(int src, int dst, int right, int n, vector<vector<pi>> &edge) {
    int left = 0, answer = 0;
    while(left <= right) {
        int mid = (left + right) / 2; // 중량 mid
        if(bfs(src, dst, mid, n, edge)) { // 1. src에서 dst까지 전달할 수 있는 경우
            answer = mid;
            left = mid + 1; // 중량 늘리기
        }
        else { // 2. src에서 dst까지 전달할 수 없는 경우
            right = mid - 1; // 중량 줄이기
        }
    }
    return answer;
}

int main() {
    int n, m, a, b, c, src, dst, max_cost = 0;
    vector<vector<pi>> edge;

    cin >> n >> m;
    edge.assign(n+1, vector<pi> (0));
    while(m--) {
        cin >> a >> b >> c;
        // 양방향 그래프
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
        max_cost = max(max_cost, c);
    }

    cin >> src >> dst;
    cout << binarySearch(src, dst, max_cost, n, edge);
    return 0;
}