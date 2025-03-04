#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntTape(int n, int l, vector<int> &pos) {
    int cnt = 1;
    double pre = (double) pos[0] - 0.5;
    for(int i = 1; i < n; i++) {
        if(pos[i] - pre >= l) {
            pre = pos[i] - 0.5;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, l;
    vector<int> pos;

    cin >> n >> l;
    pos.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());

    cout << cntTape(n, l, pos);
    return 0;
}