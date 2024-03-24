#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<pi> bridge;

    int idx = 0;
    int sec = 0;
    int n = truck_weights.size();

    while(idx < n) {
        while(!bridge.empty() && bridge.front().second <= sec) {
            weight += bridge.front().first;
            bridge.pop();
        }

        int w = truck_weights[idx];
        if(weight >= w) {
            idx++;
            weight -= w;
            bridge.push({w, sec + bridge_length});
        }
        sec++;
    }

    while(!bridge.empty()) {
        answer = bridge.front().second;
        bridge.pop();
    }
    return answer + 1;
}