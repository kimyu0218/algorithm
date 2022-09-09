#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; // 모든 트럭이 다리를 건너는데 걸리는 최소 시간
    int idx = 0, cnt = 0, truck_cnt = truck_weights.size();

    deque<pi> dq; // 다리를 지나고 있는 트럭들 저장 (front : 가장 먼저 들어간 트럭, back : 가장 나중에 들어간 트럭)
    while(cnt < truck_cnt) {
        // 1. 다리를 건너는 트럭 -> 다리를 지난 트럭
        if(!dq.empty()) {
            pi truck = dq.front();
            if(truck.first <= answer) {
                weight += truck.second;
                dq.pop_front(); cnt++;
            }
        }
        // 2. 대기 트럭 -> 다리를 건너는 트럭
        if(idx < truck_cnt && truck_weights[idx] <= weight) {
            dq.push_back({answer + bridge_length, truck_weights[idx]});
            weight -= truck_weights[idx++];
        }
        answer++;
    }
    return answer;
}