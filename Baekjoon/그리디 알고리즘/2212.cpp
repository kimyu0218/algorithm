#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> pos) {
    int n = pos.size();
    if(k >= n) {
        return 0;
    }

    sort(pos.begin(), pos.end());

    vector<int> dist(n - 1, 0);
    for(int i = 0; i < n - 1; i++) {
        dist[i] = pos[i + 1] - pos[i];
    }

    sort(dist.begin(), dist.end());

    int result = 0;
    for(int i = 0; i < n - k; i++) {
        result += dist[i];
    }
    return result;
}

int main() {
    int n, k;
    vector<int> pos;

    cin >> n >> k;

    pos.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    cout << solution(k, pos);
    return 0;
}