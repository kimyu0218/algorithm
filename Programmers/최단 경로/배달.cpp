#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 5 * 1e5 + 1;
typedef pair<int, int> pi;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    vector<vector<pi>> edge (N+1, vector<pi> ()); // (first : 다음 마을 번호, second : 도로를 지날 때 걸리는 시간)
    for(int i = 0; i < road.size(); i++) { // 간선 정보 만들기
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    vector<int> dist (N+1, INF); // dist[n] : 1번 마을에서 n번 마을까지 가는 최단시간
    priority_queue<pi, vector<pi>, greater<>> pq;

    // 시작 마을
    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(dist[node] < weight) {
            continue;
        }

        for(int i = 0; i < edge[node].size(); i++) {
            int next_node = edge[node][i].first;
            int w = edge[node][i].second;
            if(dist[next_node] > weight + w) {
                dist[next_node] = weight + w;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    for(int i = 1; i <= N; i++) { // 1번 마을에서 k시간 이하로 배달 가능한 마을 개수 구하기
        if(dist[i] <= K) {
            answer++;
        }
    }
    return answer;
}