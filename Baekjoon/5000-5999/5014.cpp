#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int NOT_VISITED = -1;

int clickButton(int f, int s, int g, int u, int d) { // f층의 고층 건물, 스타트링크는 g층, 강호는 s층, 위로 u층, 아래층으로 d층
    vector<int> btn_click (f+1, NOT_VISITED); // btn_click[i] : i층까지 가는데 필요한 버튼 클릭 횟수
    queue<int> q;
    
    // 시작지점 (강호의 위치) 세팅
    btn_click[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int dst = q.front();
        q.pop();
        
        if(dst == g) { // g층 도착
            return btn_click[g];
        }
        int up = dst + u, down = dst - d;
        if(up <= f && btn_click[up] == NOT_VISITED) { // 위층으로 이동
            btn_click[up] = btn_click[dst] + 1;
            q.push(up);
        }
        if(down >= 1 && btn_click[down] == NOT_VISITED) { // 아래층으로 이동
            btn_click[down] = btn_click[dst] + 1;
            q.push(down);
        }
    }
    return NOT_VISITED; // 엘리베이터로 이동할 수 없는 경우
}

int main() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    int answer = clickButton(f, s, g, u, d);
    if(answer == NOT_VISITED) {
        cout << "use the stairs";
    }
    else {
        cout << answer;
    }
    return 0;
}