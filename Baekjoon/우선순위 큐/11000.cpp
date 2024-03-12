#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<pi> timetable) {
    sort(timetable.begin(), timetable.end());

    priority_queue<int, vector<int>, greater<>> pq;
    pq.push(timetable[0].second);

    for(int i = 1; i < timetable.size(); i++) {
        int s = timetable[i].first;
        int t = timetable[i].second;

        if(s >= pq.top()) {
            pq.pop();
        }
        pq.push(t);
    }
    return pq.size();
}

int main() {
    int n;
    vector<pi> timetable;

    cin >> n;

    timetable.assign(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> timetable[i].first >> timetable[i].second;
    }

    cout << solution(timetable);
    return 0;
}