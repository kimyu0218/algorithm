#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int recur_sum(int idx, int n, vector<pi> consult) {
    if(idx >= n) {
        return 0;
    }

    int next = idx + consult[idx].first;
    if(next > n) {
        return recur_sum(idx + 1, n, consult);
    }
    int p = consult[idx].second;
    return max(recur_sum(next, n, consult) + p, recur_sum(idx + 1, n, consult));
}

int solution(int n, vector<pi> consult) {
    return recur_sum(0, n, consult);
}

int main() {
    int n;
    vector<pi> consult;

    cin >> n;

    consult.assign(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> consult[i].first >> consult[i].second;
    }

    cout << solution(n, consult);
    return 0;
}