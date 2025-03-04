#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef priority_queue<ll, vector<ll>, greater<>> pq;

int solution(vector<pl> lectures) {
    pq min_e;

    sort(lectures.begin(), lectures.end());
    min_e.push(lectures[0].second);

    for(int i = 1; i < lectures.size(); i++) {
        ll s = lectures[i].first;
        ll e = lectures[i].second;

        if(s >= min_e.top()) {
            min_e.pop();
        }
        min_e.push(e);
    }
    return min_e.size();
}

int main() {
    int n, num;
    vector<pl> lectures;

    cin >> n;

    lectures.assign(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> num >> lectures[i].first >> lectures[i].second;
    }

    cout << solution(lectures);
    return 0;
}