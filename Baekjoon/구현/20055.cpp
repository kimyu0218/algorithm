#include <iostream>
#include <vector>

using namespace std;
vector<pair<bool, int>> belt; // (first : 로봇 존재 여부, second : 내구도)

int count_zero(int n) { // 4번 (내구도가 0인 칸 개수 세기)
    int cnt = 0;
    for(int i = 1; i <= 2*n; i++) {
        if(!belt[i].second) cnt++;
    }
    return cnt;
}

void rotate(int n) { // 1번 (한 칸 회전)
    belt[0] = belt[2*n]; // (2n칸 정보 0칸에 임시 저장)
    for(int i = 2*n-1; i > 0; i--) {
        belt[i+1] = belt[i];
        if(i+1 == n && belt[i+1].first) belt[i+1].first = false; // 로봇 내리기
    }
    belt[1] = belt[0]; // 이동 (2n칸 -> 1칸)
}

void move(int n) { // 2번 (로봇 이동)
    for(int i = n-1; i > 0; i--) {
        // i칸에 로봇이 있고, i+1칸에 로봇이 없으며 내구도가 1 이상인 경우 로봇 이동
        if(belt[i].first && !belt[i+1].first && belt[i+1].second) {
            belt[i].first = false; belt[i+1].first = true;
            belt[i+1].second--;
        }
        if(i+1 == n && belt[i+1].first) belt[i+1].first = false; // 로봇 내리기
    }
}

void up_robot() { // 3번 (로봇 올리기)
    if(belt[1].second) {
        belt[1].first = true;
        belt[1].second--;
    }
}

int cnt_step(int n, int k) {
    int step = 1;
    while(true) {
        rotate(n); // 1번
        move(n); // 2번
        up_robot(); // 3번
        if(count_zero(n) >= k) break; // 4번
        step++;
    }
    return step;
}

int main() {
    int n, k;
    cin >> n >> k;

    belt.assign(2*n+1, {false, 0});
    for(int i = 1; i <= 2*n; i++) // 칸 내구도 입력
        cin >> belt[i].second;

    cout << cnt_step(n, k);
    return 0;
}