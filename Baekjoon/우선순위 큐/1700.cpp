#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100, UNPLUG = -1;
typedef pair<int, int> pi; // (first : 다음 등장 순서, second : 전기용품 이름)

int optScheduling(int n, int k, vector<int> &order, vector<queue<int>> &appliance) {
    int cnt = 0, u_cnt = 0;
    vector<int> plug(k+1, UNPLUG); // plug[i] : i 제품이 등장하는 다음 순서
    priority_queue<pi> outlet;

    for(int i = 0; i < k; i++) {
        while(!outlet.empty()) { // 뽑아야 하는 플러그 찾기
            int next = outlet.top().first;
            int top = outlet.top().second;
            if(next == plug[top]) {
                break;
            }
            outlet.pop();
        }

        int name = order[i];
        appliance[name].pop();
        if(plug[name] == UNPLUG && u_cnt == n) { // 멀티탭이 포화상태라 플러그를 뽑아야 하는 경우
            int top = outlet.top().second;
            outlet.pop();
            plug[top] = UNPLUG; // top 가전제품 뽑기
            cnt++; u_cnt--;
        }
        if(plug[name] == UNPLUG) { // 멀티탭에 name 전기용품 꼽기
            u_cnt++;
        }
        // 플러그 정보 갱신
        int next = (appliance[name].empty()) ? INF : appliance[name].front(); // 다음 등장 순서
        outlet.push({next, name});
        plug[name] = next;
    }
    return cnt;
}

int main() {
    int n, k;
    vector<int> order;
    vector<queue<int>> appliance;

    cin >> n >> k;
    order.assign(k, 0);
    appliance.assign(k+1, queue<int> ());
    for(int i = 0; i < k; i++) {
        cin >> order[i];
        appliance[order[i]].push(i);
    }

    cout << optScheduling(n, k, order, appliance);
    return 0;
}