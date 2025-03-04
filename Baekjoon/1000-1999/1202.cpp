#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

ll gemSum(int n, int k, vector<pi> &gem, vector<int> &c) {
    ll sum = 0;
    int idx = 0; // 보석 인덱스
    priority_queue<int> pq;

    for(int i = 0; i < k; i++) { // i : 가방 인덱스
        while(idx < n && gem[idx].first <= c[i]) { // i번째 가방이 담을 수 있는 보석
            pq.push(gem[idx++].second);
        }
        if(!pq.empty()) { // top 위치의 보석 -> i번째 가방에 집어넣기
            sum += pq.top();
            pq.pop();
        }
    }
    return sum;
}

int main() {
    int n, k, w;
    vector<pi> gem; // (first : m 무게 / second : v 가치)
    vector<int> c;

    cin >> n >> k;
    gem.assign(n, {0, 0});
    c.assign(k, 0);
    for(int i = 0; i < n; i++) { // 보석 정보 입력
        cin >> gem[i].first >> gem[i].second;
    }
    for(int i = 0; i < k; i++) { // 가방이 담을 수 있는 최대 무게
        cin >> c[i];
    }

    sort(gem.begin(), gem.end());
    sort(c.begin(), c.end());
    cout << gemSum(n, k, gem, c);
    return 0;
}