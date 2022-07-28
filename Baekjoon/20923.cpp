#include <iostream>
#include <queue>

using namespace std;

deque<int> d_deque, s_deque, d_ground, s_ground;

void put_down_do() {
    // 자신이 가진 덱에서 가장 위에 있는 카드 내려놓기
    int d = d_deque.front(); d_deque.pop_front();
    // 그라운드에 숫자가 보이도록 내려놓기
    d_ground.push_front(d);
}

void put_down_su() {
    // 자신이 가진 덱에서 가장 위에 있는 카드 내려놓기
    int s = s_deque.front(); s_deque.pop_front();
    // 그라운드에 숫자가 보이도록 내려놓기
    s_ground.push_front(s);
}

void take_another(deque<int> &deq, deque<int> &another) { // 상대방의 그라운드에 있는 카드 더미를 뒤집어 자신의 덱 아래로 합친다
    while(!another.empty()) {
        deq.push_back(another.back());
        another.pop_back();
    }
}

void take_mine(deque<int> &deq, deque<int> &mine) { // 자신의 그라운드에 있는 카드 더미를 뒤집어 자신의 덱 아래로 합친다
    while(!mine.empty()) {
        deq.push_back(mine.back());
        mine.pop_back();
    }
}

bool take_su() { // 수연이가 그라운드를 가져가는가
    if(d_ground.empty() || s_ground.empty()) return false;
    if(d_ground.front() + s_ground.front() == 5) return true; // 어느 그라운드도 비어있지 않고 가장 위에 위치한 숫자의 합이 5인 경우 이김
    return false;
}

bool take_do() { // 도도가 그라운드를 가져가는가
    if(!d_ground.empty() && d_ground.front() == 5) return true; // 가장 위에 위치한 숫자가 5인 경우 이김
    if(!s_ground.empty() && s_ground.front() == 5) return true; // 가장 위에 위치한 숫자가 5인 경우 이김
    return false;
}

void take_all() { // 그라운드에 있는 카드 가져가기
    if(take_su()) { // 수연이가 종을 치는 경우
        take_another(s_deque, d_ground);
        take_mine(s_deque, s_ground);
    }
    else if(take_do()) { // 도도가 종을 치는 경우
        take_another(d_deque, s_ground);
        take_mine(d_deque, d_ground);
    }
}

string game(int m) { // 할리 게임
    int round = 0;
    while(!d_deque.empty() && !s_deque.empty()) {
        // 도도 차례
        put_down_do();
        if(d_deque.empty()) break;
        take_all(); round++;
        if(round == m) break; // 게임 중단

        // 수연 차례
        put_down_su();
        if(s_deque.empty()) break;
        take_all(); round++;
        if(round == m) break; // 게임 중단
    }
    int d = d_deque.size(), s = s_deque.size();
    if(d == s) return "dosu";
    if(d > s) return "do";
    else return "su";
}

int main() {
    int n, m, d, s;
    cin >> n >> m; // 카드 개수, 게임 진행 횟수 입력

    while(n--) { // n장의 카드 이루어진 덱 배분 받기
        cin >> d >> s;
        // 맨 아래 -> 맨 위
        d_deque.push_front(d);
        s_deque.push_front(s);
    }
    cout << game(m);
    return 0;
}