#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> pi;
typedef priority_queue<pi> max_priority_queue;
typedef priority_queue<pi, vector<pi>, greater<>> min_priority_queue;

vector<bool> deleted;

void pop_min_pq(min_priority_queue &pq) {
    while(!pq.empty() && deleted[pq.top().second]) {
        pq.pop();
    }
    if(pq.empty()) {
        return;
    }
    int idx = pq.top().second;
    deleted[idx] = true;
    pq.pop();
}

void pop_max_pq(max_priority_queue &pq) {
    while(!pq.empty() && deleted[pq.top().second]) {
        pq.pop();
    }
    if(pq.empty()) {
        return;
    }
    int idx = pq.top().second;
    deleted[idx] = true;
    pq.pop();
}

string get_result(max_priority_queue &max_pq, min_priority_queue &min_pq) {
    while(!max_pq.empty() && deleted[max_pq.top().second]) {
        max_pq.pop();
    }
    if(max_pq.empty()) {
        return "EMPTY";
    }
    while(!min_pq.empty() && deleted[min_pq.top().second]) {
        min_pq.pop();
    }
    return to_string(max_pq.top().first) + ' ' + to_string(min_pq.top().first);
}

int main() {
    int t, k, n;
    char cmd;

    cin >> t;

    while(t--) {
        cin >> k;

        deleted.assign(k, false);
        max_priority_queue max_pq;
        min_priority_queue min_pq;

        for(int i = 0; i < k; i++) {
            cin >> cmd >> n;

            if(cmd == 'I') {
                max_pq.push({n, i});
                min_pq.push({n, i});
                continue;
            }

            if(n == -1 && !min_pq.empty()) {
                pop_min_pq(min_pq);
            }
            else if(n == 1 && !max_pq.empty()) {
                pop_max_pq(max_pq);
            }
        }
        cout << get_result(max_pq, min_pq) << '\n';
    }
    return 0;
}