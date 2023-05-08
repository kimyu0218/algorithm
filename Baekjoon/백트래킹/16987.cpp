#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
struct info{
    int s, w;
};
vector<info> egg;

void backtracking(int idx) {
    if(idx ==  n) { // 기저 조건
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += (egg[i].s <= 0);
        }
        answer = max(answer, cnt);
        return;
    }

    if(egg[idx].s <= 0) { // 1. idx 계란을 손에 들려고 하는데 해당 계란이 이미 깨져있는 경우
        backtracking(idx+1);
        return;
    }

    // 2. idx 계란으로 계란 치기
    bool crash = false;
    for(int i = 0; i < n; i++) {
        if(i == idx || egg[i].s <= 0) { // 이미 깨진 계란 pass
            continue;
        }

        egg[idx].s -= egg[i].w; // 계란 치기
        egg[i].s -= egg[idx].w;
        crash = true;
        backtracking(idx+1); // idx 계란 내려놓고 다음 계란으로 계란 치기
        egg[idx].s += egg[i].w; // 원상 복구
        egg[i].s += egg[idx].w;
    }
    if(!crash) { // idx로 깰 수 있는 계란이 없음
        backtracking(n);
    }
}

int main() {
    cin >> n;
    egg.assign(n, {0, 0});
    for(int i = 0; i < n; i++) { // 내구도와 무게 입력
        cin >> egg[i].s >> egg[i].w;
    }

    backtracking(0);
    cout << answer;
    return 0;
}