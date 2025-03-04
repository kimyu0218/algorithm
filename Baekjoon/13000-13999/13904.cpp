#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

bool cmp(const pi &p1, const pi &p2) {
    if(p1.first != p2.first) { // 1. 마감일 빠른 순
        return p1.first < p2.first;
    }
    return p1.second > p2.second; // 2. 점수 높은 순
}

int maxScore(int n, vector<pi> &assignment) {
    int sum = 0;
    priority_queue<int, vector<int>, greater<>> pq; // 웅찬이가 끝낸 과제 저장

    for(int i = 0; i < n; i++) {
        int d = assignment[i].first; // 과제 마감일
        int w = assignment[i].second; // 과제 점수
        if(pq.size() < d) {
            pq.push(w);
            continue;
        }

        // 이번에 나온 과제를 수행할 수 없는 경우
        int score = pq.top();
        if(score <= w) {
            pq.pop();
            pq.push(w);
        }
    }

    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    return sum;
}

int main() {
    int n;
    vector<pi> assignment;

    cin >> n;
    assignment.assign(n, {0, 0});
    for(int i = 0; i < n; i++) { // 과제 정보 입력
        cin >> assignment[i].first >> assignment[i].second;
    }

    sort(assignment.begin(), assignment.end(), cmp);
    cout << maxScore(n, assignment);
    return 0;
}