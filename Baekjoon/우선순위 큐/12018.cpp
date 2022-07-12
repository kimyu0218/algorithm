#include <iostream>
#include <queue>

using namespace std;

int min_mileage(int p, int l) { // 1. 최소한으로 필요한 마일리지 (p: 수강신청 인원, l: 최대 수강인원)
    priority_queue<int, vector<int>, greater<>> pq; // 마일리지 우선순위 큐
    int x;

    for(int i = 0; i < p; i++) {
        cin >> x;
        if(pq.size() == l) { // 수강인원이 다 찬 경우
            int top = pq.top();
            if(top < x) { // 우선순위 갱신
                pq.pop();
                pq.push(x);
            }
        }
        else pq.push(x);
    }
    if(p < l) return 1;
    else return pq.top();
}

int count_lecture(int m, priority_queue<int, vector<int>, greater<>> pq) { // 2. 최대로 들을 수 있는 과목수
    int cnt = 0;
    while(!pq.empty()) {
        m -= pq.top();
        if(m < 0) break;
        cnt++;
        pq.pop();
    }
    return cnt;
}

int main() {
    int n, m, p, l;
    priority_queue<int, vector<int>, greater<>> mileage;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> p >> l;
        mileage.push(min_mileage(p, l));
    }
    cout << count_lecture(m, mileage);
    return 0;
}