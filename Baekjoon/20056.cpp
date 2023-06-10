#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
struct info {
    int r, c, m, s, d;
};
vector<vector<queue<int>>> board;

void operation1(vector<info> &curr) { // 모든 파이어볼 이동
    for(int i = 0; i < curr.size(); i++) {
        int r = curr[i].r, c = curr[i].c;
        int s = curr[i].s, d = curr[i].d;

        int nr = (r + s * (n + dr[d])) % n;
        int nc = (c + s * (n + dc[d])) % n;

        curr[i].r = nr; curr[i].c = nc;
        board[nr][nc].push(i);
    }
}

void combineAndDivide(int r, int c, vector<info> &curr, vector<info> &next) {
    int m_sum = 0, s_sum = 0, odd = 0, cnt = board[r][c].size();
    while(!board[r][c].empty()) {
        int num = board[r][c].front();
        board[r][c].pop();
        m_sum += curr[num].m;
        s_sum += curr[num].s;
        odd += (curr[num].d % 2);
    }

    int m = m_sum / 5; // 새 질량
    if(m == 0) { // 새 질량이 0인 경우 소멸
        return;
    }
    int s = s_sum / cnt;
    int start = (odd == cnt || odd == 0) ? 0 : 1;
    for(int d = start; d <= 7; d+=2) { // 4개의 파이어볼 생성
        next.push_back({r, c, m, s, d});
    }
}

vector<info> operation2(vector<info> &curr) {
    vector<info> next; // 다음번 파이어볼
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j].empty()) { // 1. 비어있는 칸 pass
                continue;
            }
            if(board[i][j].size() == 1) { // 2. 하나의 파이어볼이 있는 경우
                int num = board[i][j].front();
                board[i][j].pop();
                next.push_back(curr[num]);
            }
            else { // 3. 같은 칸에 두 개 이상의 파이어볼이 있는 경우
                combineAndDivide(i, j, curr, next);
            }
        }
    }
    return next;
}

int magicShark(int k, vector<info> &curr) {
    int sum = 0;
    while(k--) { // k번의 명령 실행
        operation1(curr); // 1번 연산
        curr = operation2(curr); // 2번 연산
    }
    for(int i = 0; i < curr.size(); i++) {
        sum += curr[i].m;
    }
    return sum;
}

int main() {
    int m, k, r, c;
    vector<info> curr; // 현재 파이어볼 정보

    cin >> n >> m >> k;
    board.assign(n, vector<queue<int>> (n, queue<int> ()));
    curr.assign(m, {});

    for(int i = 0; i < m; i++) { // 파이어볼 정보 입력
        cin >> r >> c >> curr[i].m >> curr[i].s >> curr[i].d;
        curr[i].r = r-1;
        curr[i].c = c-1;
    }

    cout << magicShark(k, curr);
    return 0;
}