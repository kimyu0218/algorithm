#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;
typedef priority_queue<ll, vector<ll>, greater<>> min_pq;

min_pq init_pq(vector<int> &a) {
    min_pq pq;
    for(int i = 0; i < a.size(); i++) {
        pq.push(a[i]);
    }
    return pq;
}

ll get_sum(min_pq pq) {
    ll sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    return sum;
}

ll solution(int m, vector<int> a) {
    min_pq pq = init_pq(a);

    while(m--) {
        ll x = pq.top();
        pq.pop();
        ll y = pq.top();
        pq.pop();
        ll sum = x + y;
        pq.push(sum);
        pq.push(sum);
    }
    return get_sum(pq);
}

int main() {
    int n, m;
    vector<int> a;

    cin >> n >> m;

    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solution(m, a);
    return 0;
}