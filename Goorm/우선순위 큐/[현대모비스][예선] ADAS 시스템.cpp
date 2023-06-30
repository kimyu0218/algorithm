#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> pi;

int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0}; // 상 좌 우 하
map<char, int> prior = {{'E', 1}, {'P', 2}, {'0', 3}}; // 우선순위 E > P > 0

struct info {
    int p, a, b;
};
struct cmp {
    bool operator() (const info &i1, const info &i2) {
        if(i1.p != i2.p) { // 1. 우선순위 높은 순
            return i1.p > i2.p;
        }
        if(i1.a != i2.a) { // 2. a 작은 순
            return i1.a > i2.a;
        }
        return i1.b > i2.b; // 3. b 작은 순
    }
};

int cntP(int a, int b, int w, int h, vector<vector<char>> &board) { // 주변 3X3에서 P점 개수 세기
    int cnt = 0;
    int sa = a-1, ea = a+1;
    int sb = b-1, eb = b+1;
    for(int i = sa; i <= ea; i++) {
        if(i < 0 || i >= w) { // 좌표 벗어남
            continue;
        }
        for(int j = sb; j <= eb; j++) {
            if(j < 0 || j >= h) { // 좌표 벗어남
                continue;
            }
            if(i == a && j == b) { // 자기 자신 제외
                continue;
            }
            if(board[i][j] == 'P') {
                cnt++;
            }
        }
    }
    return cnt;

}

int adas(int w, int h, pi s, vector<vector<char>> &board) {
    int score = 0;
    priority_queue<info, vector<info>, cmp> pq;
    vector<vector<bool>> visited(w, vector<bool> (h, false));

    pq.push({0, s.first, s.second});
    visited[s.first][s.second] = true;

    while(!pq.empty()) {
        int p = pq.top().p;
        int a = pq.top().a;
        int b = pq.top().b;
        pq.pop();


        if(p == 1) { // E점 발견 (== 도착)
            break;
        }
        if(p == 2) { // p점 발견
            int p_cnt = cntP(a, b, w, h, board);
            score += (p_cnt-3);
        }
        else if(p == 3) { // 0점 발견
            int p_cnt = cntP(a, b, w, h, board);
            score += p_cnt;
        }

        // 인접한 칸 탐색
        for(int i = 0; i < 4; i++) {
            int na = a + dr[i];
            int nb = b + dc[i];
            // 아직 방문하지 않은 지점 발견
            if(na >= 0 && na < w && nb >= 0 && nb < h && !visited[na][nb]) {
                visited[na][nb] = true;
                pq.push({prior[board[na][nb]], na, nb});
            }
        }
    }
    if(score < 0) { // 위험점수가 0보다 작은 경우 0으로 측정
        return 0;
    }
    return score;
}

int main() {
    int w, h;
    pi s;
    vector<vector<char>> board;

    cin >> w >> h;
    board.assign(w, vector<char> (h, '\0'));
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'S') {
                s = {i, j};
            }
        }
    }

    cout << adas(w, h, s, board);
    return 0;
}