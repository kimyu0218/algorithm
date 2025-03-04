#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

bool cmp(pi &p1, pi &p2) {
    if(p1.second != p2.second) {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

int solution(vector<pi> timetable) {
    int result = 0;
    int pre_end_time = 0;

    sort(timetable.begin(), timetable.end(), cmp);

    for(int i = 0; i < timetable.size(); i++) {
        int s = timetable[i].first;
        if(s < pre_end_time) {
            continue;
        }
        result++;
        pre_end_time = timetable[i].second;
    }
    return result;
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