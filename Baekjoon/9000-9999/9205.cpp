#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
const int MAX_DIST = 1000, LIMIT = 32768;
vector<pi> pos; // 좌표

string canReach(int n) {
    queue<int> q;

    // 시작지점 세팅 (상근이네 집 좌표)
    q.push(0);

    while(!q.empty()) {
        int idx = q.front(); q.pop(); // idx : 출발점 인덱스
        if(idx == n+1) { // 락 페스티벌에 도착한 경우
            return "happy";
        }

        for(int i = 1; i <= n+1; i++) { // i : 도착점 인덱스
            if(i == idx || pos[i].first == LIMIT) { // 출발점과 도착점이 같거나 이미 방문했던 좌표는 pass
                continue;
            }
            int dist = abs(pos[idx].first - pos[i].first) + abs(pos[idx].second - pos[i].second); // 맨해튼 거리 계산
            if(dist <= MAX_DIST) {
                q.push(i);
            }
        }
        pos[idx] = {LIMIT, LIMIT}; // 방문 체크
    }
    return "sad"; // 락 페스티벌에 도착할 수 없는 경우
}

int main() {
    int t, n;

    cin >> t;
    while(t--) { // 테스트케이스
        cin >> n;
        pos.assign(n+2, {0, 0});
        for(int i = 0; i < n+2; i++) { // 좌표 입력 (0 : 상근이네 집, n+1 : 페스티벌 좌표)
            cin >> pos[i].first >> pos[i].second;
        }
        cout << canReach(n) << '\n';
    }
    return 0;
}