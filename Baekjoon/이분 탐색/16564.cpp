#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll level_up(int k, int n, vector<int> x) {
    ll answer = 0;
    for(int i = 0; i < n; i++) {
        if(x[i] >= k) {
            return answer;
        }
        answer += (k - x[i]);
    }
    return answer;
}

int solution(int k, vector<int> x) {
    int answer = 0;
    int n = x.size();

    sort(x.begin(), x.end());

    ll left = x[0];
    ll right = x[n - 1] + k;

    while(left <= right) {
        ll mid = (left + right) / 2;
        ll level = level_up(mid, n, x);

        if(level <= k) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return answer;
}

int main() {
    int n, k;
    vector<int> x;

    cin >> n >> k;

    x.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << solution(k, x);
    return 0;
}