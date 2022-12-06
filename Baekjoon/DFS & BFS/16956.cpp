#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}; // 상 하 좌 우

bool canEat(int r, int c, vector<vector<char>> farm, queue<pi> wolf) { // 늑대가 양을 잡아먹을 수 있는가
    while(!wolf.empty()) {
        int row = wolf.front().first, col = wolf.front().second;
        wolf.pop();

        for(int i = 0; i < 4; i++) { // 양 탐색
            int new_row = row + dy[i], new_col = col + dx[i];
            if(new_row < 0 || new_row >= r || new_col < 0 || new_col >= c) { continue; } // 좌표 벗어남
            if(farm[new_row][new_col] == 'S') { // 양 발견
                return true;
            }
        }
    }
    return false; // 양 잡아먹을 수 없음 (울타리에 막힘)
}

void installFence(int r, int c, vector<vector<char>> farm, queue<pi> wolf) { // 늑대 주변에 울타리 설치하기
    while(!wolf.empty()) {
        int row = wolf.front().first, col = wolf.front().second;
        wolf.pop();

        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i], new_col = col + dx[i];
            if(new_row < 0 || new_row >= r || new_col < 0 || new_col >= c) { continue; } // 좌표 벗어남
            if(farm[new_row][new_col] == '.') { // 늑대 주위의 빈칸에 울타리 설치
                farm[new_row][new_col] = 'D';
            }
        }
    }

    for(int i = 0; i < r; i++) { // 울타리 설치한 목장 상태 출력
        for(int j = 0; j < c; j++) {
            cout << farm[i][j];
        }
        cout << '\n';
    }
}

int main() {
    int r, c;
    cin >> r >> c;

    string input;
    vector<vector<char>> farm(r, vector<char> (c, '\0'));
    queue<pi> wolf;

    for(int i = 0; i < r; i++) { // 목장 상태 입력
        cin >> input;
        for(int j = 0; j < c; j++) {
            farm[i][j] = input[j];
            if(farm[i][j] == 'W') { // 늑대 발견 -> 좌표 큐에 push
                wolf.push({i, j});
            }
        }
    }

    bool eat = canEat(r, c, farm, wolf);
    if(eat) { // 늑대가 양 잡아먹는 경우
        cout << '0';
    }
    else { // 늑대가 울타리에 막혀 양을 잡아먹을 수 없는 경우
        cout << "1\n";
        installFence(r, c, farm, wolf); // 울타리 설치
    }
    return 0;
}