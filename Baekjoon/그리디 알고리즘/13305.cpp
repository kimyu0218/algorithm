#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 1e9;

ll solution(vector<int> len, vector<int> cost) {
    ll result = 0;
    int n = len.size();
    int min_cost = MAX;

    for(int i = 0; i < n; i++) {
        min_cost = min(min_cost, cost[i]);
        result += (ll) len[i] * min_cost;
    }
    return result;
}

int main() {
    int n;
    vector<int> len;
    vector<int> cost;

    cin >> n;

    len.assign(n - 1, 0);
    for(int i = 0; i < n - 1; i++) {
        cin >> len[i];
    }

    cost.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    cout << solution(len, cost);
    return 0;
}