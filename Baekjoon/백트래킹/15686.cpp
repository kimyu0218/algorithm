#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
const int SIZE = 50, SELECTED = 13, HOME_MAX = 100, CITY_MAX = SIZE * HOME_MAX;

int n, m;
int answer = CITY_MAX;
int city[SIZE][SIZE]; // 도시 정보
vector<pi> home, chicken; // 집 위치, 치킨집 위치
pi selected[SELECTED]; // 영업중인 치킨집 위치

int home_dist(int hr, int hc) { // 집에서 가장 가까운 치킨집까지의 거리
    int dist = HOME_MAX;
    for(int i = 0; i < m; i++) {
        int row = selected[i].first, col = selected[i].second;
        dist = min(dist, abs(hr-row) + abs(hc-col));
    }
    return dist;
}

void backtracking(int start, int cnt) { // (cnt : 영업 중인 치킨집 수)
    if(cnt == m) { // m개 치킨집 고름
        int sum = 0; // 도시의 치킨 거리 저장
        for(int i = 0; i < home.size(); i++) {
            sum += home_dist(home[i].first, home[i].second);
        }
        answer = min(sum, answer);
        return;
    }

    for(int i = start; i < chicken.size(); i++) {
        int row = chicken[i].first, col = chicken[i].second;
        selected[cnt] = {row, col};
        backtracking(i+1, cnt+1);
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) { // 도시 정보 입력
        for(int j = 0; j < n; j++) {
            cin >> city[i][j];
            if(city[i][j] == 1) home.push_back({i, j}); // 집 발견
            else if(city[i][j] == 2) chicken.push_back({i, j}); // 치킨집 발견
        }
    }

    backtracking(0, 0);
    cout << answer;
    return 0;
}