#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e9;
vector<vector<ci>> computer;

ci dijkstra(int start, int n) {
    ci answer = {0, 0}; // (first : 감염된 컴퓨터 수, second : 마지막 컴퓨터를 감염시키는 데 걸린 시간)
    vector<int> time(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    // 해킹된 컴퓨터 push
    time[start] = 0; pq.push({0, start});

    while(!pq.empty()) {
        int b = pq.top().second;
        int s = pq.top().first;
        pq.pop();

        if(s > time[b]) continue; // 이미 탐색한 컴퓨터 pass

        // (b 컴퓨터가 a 컴퓨터를 감염시키려고 함)
        for(int i = 0; i < computer[b].size(); i++) {
            int a = computer[b][i].first;
            int new_s = s + computer[b][i].second;
            if(time[a] > new_s) {
                time[a] = new_s;
                pq.push({new_s, a});
            }
        }
    }
    // 총 몇 대의 컴퓨터가 감염되며 그에 걸리는 시간이 얼마인지
    for(int i = 1; i <= n; i++) {
        if(time[i] != INF) { // 감염된 컴퓨터 발견
            answer.first++;
            answer.second = max(answer.second, time[i]);
        }
    }
    return answer;
}

int main() {
    int t, n, d, c, a, b, s;
    cin >> t;

    while(t--) { // 테스트 케이스
        cin >> n >> d >> c;

        computer.assign(n+1, vector<ci> (0));
        while(d--) {
            cin >> a >> b >> s;
            // b가 감염되면 s초 후 a도 감염된다
            computer[b].push_back({a, s});
        }
        // (해킹된 컴퓨터가 모든 컴퓨터를 감염시키고자 함)
        ci ans = dijkstra(c, n);
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}