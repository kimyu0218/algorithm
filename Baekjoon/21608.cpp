#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int, int> pi;
const int MAX = 20;
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1}; // 상 좌 하 우
int board[MAX][MAX], graph[MAX*MAX+1][4];

// 첫번째 경우의 수 : 비어있는 칸 중 좋아하는 학생이 인접한 칸에 가장 많은 칸 찾기
vector<pi> cntOne(int n, int s) {
    int cnt = -1;
    vector<pi> answer;

    for(int i = 0; i < n*n; i++) {
        int r = i / n, c = i % n;
        if(!board[r][c]) { // 빈 칸 발견
            int tmp = 0;
            for(int j = 0; j < 4; j++) { // 인접한 칸 탐색
                int nr = r + dr[j];
                int nc = c + dc[j];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc]) {
                    for(int k = 0; k < 4; k++) {
                        if(graph[s][k] == board[nr][nc]) { // 좋아하는 학생 발견
                            tmp++;
                            break;
                        }
                    }
                }
            }
            if(tmp > cnt) { // 답 갱신
                cnt = tmp;
                answer = {{r, c}};
            }
            else if(tmp == cnt) { // 답 추가
                answer.push_back({r, c});
            }
        }
    }
    return answer;
}

// 두번째 경우의 수 : 인접한 중 비어있는 칸이 가장 많은 칸 찾기
vector<pi> cntTwo(int n, vector<pi> one) {
    int cnt = -1;
    vector<pi> answer;

    for(int i = 0; i < one.size(); i++) {
        int r = one[i].first, c = one[i].second;
        int tmp = 0;
        for(int j = 0; j < 4; j++) { // 인접한 칸 탐색
            int nr = r + dr[j];
            int nc = c + dc[j];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && !board[nr][nc]) { // 빈 칸 발견
                tmp++;
            }
        }
        if(tmp > cnt) { // 답 갱신
            cnt = tmp;
            answer = {{r, c}};
        }
        else if(tmp == cnt) { // 답 추가
            answer.push_back({r, c});
        }
    }
    return answer;
}

void seatDown(int n, int s) { // s 학생 앉히기
    int r, c;
    vector<pi> one = cntOne(n, s);
    if(one.size() == 1) { // 첫번째 경우의 수가 하나인 경우
        r = one[0].first;
        c = one[0].second;
    }
    else { // 첫번째 경우가 여러 개인 경우, 두번째 경우 구하기
        vector<pi> two = cntTwo(n, one);
        r = two[0].first;
        c = two[0].second;
    }
    board[r][c] = s;
}

int computeSatisfaction(int n) { // 학생의 만족도 합 구하기
    int sum = 0; // 학생 만족도 총합

    for(int i = 0; i < n*n; i++) {
        int r = i / n, c = i % n;
        int cnt = 0, s = board[r][c];

        for(int j = 0; j < 4; j++) { // s 학생의 만족도 구하기
            int nr = r + dr[j];
            int nc = c + dc[j];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
                for(int k = 0; k < 4; k++) {
                    if(board[nr][nc] == graph[s][k]) { // 인접한 칸에 좋아하는 학생 발견
                        cnt++;
                        break;
                    }
                }
            }
        }
        sum += pow(10, cnt-1); // s 학생의 만족도 더하기
    }
    return sum;
}

int main() {
    int n, s;

    cin >> n;
    for(int i = 0; i < n*n; i++) {
        cin >> s;
        for(int j = 0; j < 4; j++) { // s 학생이 좋아하는 학생 입력
            cin >> graph[s][j];
        }
        seatDown(n, s);
    }

    cout << computeSatisfaction(n);
    return 0;
}