#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;

int main() {
    int w, h;
    cin >> w >> h;

    // 짝수 열은 오른쪽, 하향, 우하향으로만 이동 가능
    // 홀수 열은 오른쪽, 하향, 좌하향, 우하향으로 이동 가능
    map.assign(h, vector<int> (w, 0));
    visited.assign(h, vector<bool> (w, false));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            cin >> map[i][j];
    }
    return 0;
}