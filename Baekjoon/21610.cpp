#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> pi;
const int SIZE = 50, MAX = 100;

int n;
int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 방향 정보
int water[SIZE][SIZE]; // 물의 양
pi info[MAX]; // 이동 정보
pi cloud[SIZE * SIZE]; // 구름 위치 정보 (row, col)

set<pi> move(int d, int s, int cloud_cnt) { // 구름 이동
    set<pi> tmp_cloud; // 비 내릴 구름 위치 (=새로운 위치)

    for(int j = 0; j < cloud_cnt; j++) {
        // 새로운 구름 위치
        int row = (cloud[j].first + dr[d] * (s % n) + n) % n;
        int col = (cloud[j].second + dc[d] * (s % n) + n) % n;
        tmp_cloud.insert({row, col});

        // 비 내리기
        water[row][col]++;
    }
    return tmp_cloud;
}

void magic(set<pi> tmp_cloud) { // 물복사버그 마법
    for(auto iter = tmp_cloud.begin(); iter != tmp_cloud.end(); iter++) { // 물복사버그 마법 (대각선 방향)
        int row = iter->first, col = iter->second; // 구름 위치

        int cnt = 0;
        for(int k = 1; k < 8; k += 2) { // k : 대각선 방향
            int nr = row + dr[k], nc = col + dc[k];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue; // 경계를 넘어가는 칸 pass
            if(water[nr][nc]) cnt++;
        }
        water[row][col] += cnt;
    }
}

int makeCloud(set<pi> tmp_cloud) { // 구름 만들기 (tmp_cloud: 구름 위치 == 사라져야 하는 구름)
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(tmp_cloud.find({i, j}) != tmp_cloud.end()) continue; // 구름 사라진 칸 pass
            if(water[i][j] >= 2) { // 구름 생성, 물의 양 수정
                cloud[cnt++] = {i, j};
                water[i][j] -= 2;
            }
        }
    }
    return cnt; // 구름 개수 반환
}

int totalWater() { // 바구니에 들어있는 물의 양 구하기
    int total = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            total += water[i][j];
        }
    }
    return total;
}

int shark(int m) {
    int cloud_cnt = 4; // (초기 구름 개수 : 4)
    for(int i = 0; i < m; i++) {
        int d = info[i].first-1, s = info[i].second; // 구름 이동 정보
        set<pi> tmp_cloud = move(d, s, cloud_cnt); // 새로운 구름 위치
        magic(tmp_cloud); // 물복사버그 마법 실행
        cloud_cnt = makeCloud(tmp_cloud); // 구름 만들기
    }
    return totalWater();
}

int main() {
    int m;
    cin >> n >> m;
    // 구름 위치 초기화
    cloud[0] = {n-1, 0}; cloud[1] = {n-1, 1};
    cloud[2] = {n-2, 0}; cloud[3] = {n-2, 1};

    for(int i = 0; i < n; i++) { // 물의 양 입력
        for(int j = 0; j < n; j++)
            cin >> water[i][j];
    }

    for(int i = 0; i < m; i++) // 이동 정보 입력
        cin >> info[i].first >> info[i].second; // (방향, 칸 개수)

    cout << shark(m);
    return 0;
}