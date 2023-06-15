#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

bool cmp(const pi &p1, const pi &p2) { // 달력 규칙
    if(p1.first != p2.first) { // 1. 시작일이 가장 앞선 일정부터
        return p1.first < p2.first;
    }
    return p1.second > p2.second; // 2. 시작일이 같을 경우 일정의 기간이 긴 것이 먼저
}

int solution(int n, vector<pi> &schedule) {
    int sum = 0, h = 1, start = schedule[0].first, end = schedule[0].second;
    priority_queue<int, vector<int>, greater<>> pq; // 종료일자 빠른 순 저장
    pq.push(schedule[0].second);

    for(int i = 1; i < n; i++) {
        int s = schedule[i].first;
        int e = schedule[i].second;

        if(s > end+1) { // 1. 비연속 구간 발견
            // 1-1. 연속된 일정을 모두 감싸는 직사각형 면적 계산
            sum += (end-start+1) * h;
            // 1-2. 구간 재설정
            start = s; end = e;
            pq = {}; pq.push(e);
            h = 1;
            continue;
        }
        if(s > pq.top()) { // 2. 시작일이 가장 빠른 종료일자보다 느린 경우, 이어붙이기 가능
            pq.pop();
        }
        pq.push(e);
        end = max(end, e);
        h = max(h, (int) pq.size());
    }
    // 마지막 직사각형 면적 추가
    sum += (end-start+1) * h;
    return sum;
}

int main() {
    int n;
    vector<pi> schedule;

    cin >> n;
    schedule.assign(n, {});
    for(int i = 0; i < n; i++) { // 일정 입력
        cin >> schedule[i].first >> schedule[i].second;
    }

    sort(schedule.begin(), schedule.end(), cmp);
    cout << solution(n, schedule);
    return 0;
}