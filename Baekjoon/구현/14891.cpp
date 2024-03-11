#include <iostream>

using namespace std;

const int WHEEL = 4;
int pointer[WHEEL+1][2]; // (0 : 오른쪽 톱니바퀴와 맞닿는 부분, 1 : 왼쪽 톱니바퀴와 맞닿는 부분)
int cogwheel[WHEEL+1][8];

void set_pointer() {
    for(int i = 1; i <= WHEEL; i++) {
        pointer[i][0] = 2;
        pointer[i][1] = 6;
    }
}

void rotate(int num, int dir, int pre) { // (pre : num 톱니바퀴를 회전시키는 톱니바퀴)
    // 1. num 톱니바퀴가 회전하기 전에 왼쪽, 오른쪽 톱니바퀴 회전시킬지 판단
    // 인접한 왼쪽 톱니바퀴 회전
    if(pre != num-1 && num-1 >= 1 && cogwheel[num][pointer[num][1]] != cogwheel[num-1][pointer[num-1][0]]) rotate(num-1, -dir, num);
    // 인접한 오른쪽 톱니바퀴 회전
    if(pre != num+1 && num+1 <= WHEEL && cogwheel[num][pointer[num][0]] != cogwheel[num+1][pointer[num+1][1]]) rotate(num+1, -dir, num);

    // 2. num 톱니바퀴 회전
    if(dir == 1) { // 시계 방향 회전 (1)
        pointer[num][0] = (pointer[num][0] + 7) % 8;
        pointer[num][1] = (pointer[num][1] + 7) % 8;
    }
    else { // 반시계 방향 회전 (-1)
        pointer[num][0] = (pointer[num][0] + 1) % 8;
        pointer[num][1] = (pointer[num][1] + 1) % 8;
    }
}

int compute_score() { // 점수 계산
    int score = 0, round_score = 1; // 총 획득한 점수, 라운드별 점수
    for(int i = 1; i <= WHEEL; i++) {
        int twelve = (pointer[i][0] + 6) % 8;
        if(cogwheel[i][twelve]) score += round_score;
        round_score *= 2;
    }
    return score;
}

int main() {
    string input;
    for(int i = 1; i <= WHEEL; i++) { // 톱니바퀴 정보 입력
        cin >> input;
        for(int j = 0; j < 8; j++)
            cogwheel[i][j] = input[j] - '0';
    }
    set_pointer();

    int k, num, dir;
    cin >> k;
    for(int i = 0; i < k; i++) { // 회전
       cin >> num >> dir;
        rotate(num, dir, num);
    }

    cout << compute_score(); // 점수 출력
    return 0;
}