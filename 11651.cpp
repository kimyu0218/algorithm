#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> xy;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    if(p1.second != p2.second) return p1.second < p2.second; // y 좌표 오름차순
    return p1.first < p2.first; // x 좌표 오름차순
}

int main() {
    int n, x, y;
    cin >> n;

    xy.assign(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        xy[i] = make_pair(x,y);
    }

    sort(xy.begin(), xy.end(), cmp); // 정렬
    for(int i = 0; i < n; i++)
        cout << xy[i].first << ' ' << xy[i].second << '\n';
    return 0;
}