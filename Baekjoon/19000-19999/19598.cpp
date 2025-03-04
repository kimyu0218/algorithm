#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
typedef priority_queue<int, vector<int>, greater<>> pq;

int solution(vector<pi> schedule) {
    pq min_e;

    sort(schedule.begin(), schedule.end());
    min_e.push(schedule[0].second);

    for(int i = 1; i < schedule.size(); i++) {
        int s = schedule[i].first;
        int e = schedule[i].second;

        if(s >= min_e.top()) {
            min_e.pop();
        }
        min_e.push(e);
    }
    return min_e.size();
}

int main() {
    int n;
    vector<pi> schedule;

    cin >> n;

    schedule.assign(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> schedule[i].first >> schedule[i].second;
    }

    cout << solution(schedule);
    return 0;
}