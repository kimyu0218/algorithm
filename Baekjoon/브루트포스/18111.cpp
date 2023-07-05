#include <iostream>
#include <vector>

using namespace std;
const int INF = 128 * 1e6;
typedef pair<int, int> pi;

pi answer = {INF, INF}; // (first : 최소시간, second : 땅 높이)

int computeTime(int height, int n, int m, int b, vector<vector<int>> &h) {
    int time = 0; // 땅 고르는 데 걸린 시간
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool inven = h[i][j] > height;
            int diff = abs(h[i][j] - height);
            if(inven) { // 1. 인벤토리에 집어넣기
                b += diff;
                time += (2 * diff);
            }
            else { // 2. 인벤토리에서 꺼내기
                b -= diff;
                time += diff;
            }
        }
    }
    if(b < 0) { // 인벤토리의 사용량을 초과한 경우 -1 반환
        return -1;
    }
    return time;
}

void bruteforce(int n, int m, int b, vector<vector<int>> &h) {
    for(int i = 0; i <= 256; i++) { // i : 땅의 높이
        int time = computeTime(i, n, m, b, h);
        if(time == -1) { // 인벤토리 사용량을 초과한 경우 pass
            continue;
        }
        if(time <= answer.first) { // 최소시간 갱신
            answer = {time, i};
        }
    }
}

int main() {
    int n, m, b;
    vector<vector<int>> h;

    cin >> n >> m >> b;
    h.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> h[i][j];
        }
    }

    bruteforce(n, m, b, h);
    cout << answer.first << ' ' << answer.second;
    return 0;
}