#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct cor{ // 좌표 구조체
    int x, y;
};
vector<cor> xy;

bool cmp(const cor &p1, const cor &p2) {
    if(p1.y != p2.y) return p1.y < p2.y; // y 좌표 오름차순
    return p1.x < p2.x; // x 좌표 오름차순
}

int main() {
    int n;
    cin >> n;
    xy.assign(n, {0, 0});
    for(int i = 0; i < n; i++)
        cin >> xy[i].x >> xy[i].y;

    sort(xy.begin(), xy.end(), cmp); // 정렬
    for(int i = 0; i < n; i++)
        cout << xy[i].x << ' ' << xy[i].y << '\n';
    return 0;
}