#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string dirs) {
    int x = 0, y = 0; // 초기 위치

    map<vector<int>, int> path; // 캐릭터가 지나간 길
    map<char, int> dir = {{'U', 0} , {'D', 1}, {'R', 2}, {'L', 3}};
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1}; // U D R L

    for(int i = 0; i < dirs.length(); i++) {
        int d = dir[dirs[i]]; // 방향
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx < -5 || nx > 5 || ny < -5 || ny > 5) { // 좌표를 벗어나는 경우 pass
            continue;
        }
        if(x < nx) {
            path[{x, y, nx, ny}]++;
        }
        else if(y < ny) {
            path[{x, y, nx, ny}]++;
        }
        else {
            path[{nx, ny, x, y}]++;
        }
        x = nx; y = ny;
    }
    return path.size();
}