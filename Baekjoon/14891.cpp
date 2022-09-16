#include <iostream>
#include <vector>

using namespace std;

bool slide(int n, int start, int end, int height, vector<int> line, vector<bool> &visited) { // 경사로를 설치할 수 있는가
    if(start < 0 || end > n) return false;

    for(int i = start; i <= end; i++) {
        if(visited[i]) return false; // 이미 경사로가 설치되어 있는 경우
        if(line[i] != height) return false; // 경사로 설치할 수 없는 경우 (평지 아님)
        visited[i] = true;
    }
    return true;
}

bool check(int n, int l, vector<int> line) { // 길을 만들 수 있는가
    int pre = line[0];
    vector<bool> visited(n, false);

    for(int i = 1; i < n; i++) {
        // 1. 높이 2 이상 차이 나는 경우
        if(abs(line[i] - pre) > 1) return false;
        // 2. 올라가는 방향으로 경사로 설치
        else if(pre < line[i]) {
            if(!slide(n, i-l, i-1, pre, line, visited)) return false;
            pre = line[i];
        }
        // 3. 내려가는 방향으로 경사로 설치
        else if(pre > line[i]) { // 3. down
            if(!slide(n, i, i+l-1, line[i], line, visited)) return false;
            pre = line[i]; i += (l-1);
        }
    }
    return true;
}

int cnt_route(int n, int l, vector<vector<int>> map) { // 지나갈 수 있는 길 개수
    int cnt = 0;
    // 가로줄 검사
    for(int i = 0; i < n; i++) cnt += check(n, l, map[i]);
    // 세로줄 검사
    for(int i = 0; i < n; i++) {
        vector<int> line;
        for(int j = 0; j < n; j++) line.push_back(map[j][i]);
        cnt += check(n, l, line);
    }
    return cnt;
}

int main() {
    int n, l;
    cin >> n >> l;

    vector<vector<int>> map (n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) { // 지도 입력
        for(int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    cout << cnt_route(n, l, map);
    return 0;
}