#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
struct info {
    int x, y, idx, cnt;
};

bool cmp(const pi &p1, const pi &p2) {
    return p1.second < p2.second;
}

int bfs(int n, int t, vector<pi> &furrow) {
    vector<bool> visited(n, false);
    queue<info> q;

    q.push({0, 0, 0, 0}); // 시작 지점 0

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int idx = q.front().idx;
        int cnt = q.front().cnt;
        q.pop();

        if(y == t) { // 정상까지 등반 완료
            return cnt;
        }

        for(int i = idx; i < n; i++) {
            int nx = furrow[i].first;
            int ny = furrow[i].second;
            if(!visited[i]) {
                int dx = abs(x-nx), dy = abs(y-ny);
                if(dx <= 2 && dy <= 2) {
                    visited[i] = true;
                    q.push({nx, ny, i, cnt+1});
                }
                else if(dx > 2 && dy > 2) {
                    break;
                }
            }
        }

        for(int i = idx; i >= 0; i--) {
            int nx = furrow[i].first;
            int ny = furrow[i].second;
            if(!visited[i]) {
                int dx = abs(x-nx), dy = abs(y-ny);
                if(dx <= 2 && dy <= 2) {
                    visited[i] = true;
                    q.push({nx, ny, i, cnt+1});
                }
                else if(dx > 2 && dy > 2) {
                    break;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, t;
    vector<pi> furrow;

    cin >> n >> t;
    furrow.assign(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> furrow[i].first >> furrow[i].second;
    }
    sort(furrow.begin(), furrow.end(), cmp);

    cout << bfs(n, t, furrow);
    return 0;
}