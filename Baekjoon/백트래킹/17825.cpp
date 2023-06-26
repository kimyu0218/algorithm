#include <iostream>
#include <map>

using namespace std;

const int TURN = 10, PLAYER = 4, CELLS = 52;
int answer = 0;
int dice[TURN], pos[PLAYER]; // 주사위 값, 말의 위치
bool visited[CELLS+1]; // 방문 여부
map<int, int> m = {{1, 25}, {2, 33}, {3, 40}}; // 분기점 만난 경우 더해줘야 하는 값

void backtracking(int over, int turn, int score) { // (over : 도착점에 도착한 말 개수)
    if(over == PLAYER || turn == TURN) { // 기저조건 : 모든 말이 도착점에 도착했거나, 모든 이동을 마친 경우
        answer = max(answer, score);
        return;
    }

    for(int i = 0; i < PLAYER; i++) { // i : 말
        if(pos[i] == -1) { // 이미 도착한 말 PASS
            continue;
        }

        // 현재 위치에서 이동 시작
        visited[pos[i]] = false;
        int tmp = pos[i];

        int new_pos, new_score;
        if(pos[i] && pos[i] <= 15 && pos[i] % 5 == 0) { // 1. 현재 위치가 분기점인 경우
            new_pos = m[pos[i]/5] + dice[turn];
        }
        else { // 2. 현재 위치가 분기점이 아닌 경우
            new_pos = pos[i] + dice[turn];
        }

        if(new_pos > 25) { // 1. 지름길로 빠지는 경우
            if(new_pos <= 33) { // 1-1. 첫번재 분기점(5)에서 이동한 경우
                new_score = 10 + 3*(new_pos-25);
                if(new_pos >= 29) {
                    new_pos = 49 + (new_pos-29);
                }
            }
            else if(new_pos <= 40) { // 1-2. 두번째 분기점(10)에서 꺾어야 하는 경우
                new_score = 20 + 2*(new_pos-33);
                if(new_pos >= 36) {
                    new_pos = 49 + (new_pos-36);
                }
            }
            else if(new_pos <= 48) { // 1-3. 세번째 분기점(15)에서 꺾어야 하는 경우
                new_score = 29 - (new_pos-40);
                if(new_pos >= 44) {
                    new_pos = 49 + (new_pos-44);
                }
            }
            if(new_pos >= 49) { // 1-4. 네번째 분기점(29 == 36 == 44 == 49)에서 이동하는 경우
                new_score = 25 + (new_pos-49) * 5;
            }
        }
        else { // 2. 빙 둘러서 가는 경우
            new_score = 2 * new_pos;
        }

        if(new_pos == 52) { // 52번 위치는 20번(=40점) 위치와 같음
            new_pos = 20;
        }

        if((new_pos >= 21 && new_pos <= 25) || new_pos >= 53) { // 1. 도착점에 도착한 경우
            pos[i] = -1;
            backtracking(over+1, turn+1, score);
        }
        else if(!visited[new_pos]){ // 2. 도착점에 도착하지 못했고 해당 위치에 다른 말이 없어 이동할 수 있는 경우
            visited[new_pos] = true;
            pos[i] = new_pos;
            backtracking(over, turn+1, score + new_score);
            visited[new_pos] = false;
        }

        // 현재 위치로 돌아오기
        pos[i] = tmp;
        visited[pos[i]] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < TURN; i++) { // 주사위 숫자 입력
        cin >> dice[i];
    }

    visited[0] = true;
    backtracking(0, 0, 0);
    cout << answer;
    return 0;
}