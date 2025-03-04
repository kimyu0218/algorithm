#include <iostream>
#include <map>
#include <stack>

using namespace std;
map<int, stack<int>> m;

void press(int note, int fret, int &cnt) { // 프렛 누르기
    m[note].push(fret); cnt++;
}

void depress(int note, int &cnt) { // 프렛 떼어내기
    m[note].pop(); cnt++;
}

int main() {
    int n, p, note, fret, cnt = 0;
    cin >> n >> p;

    for(int i = 0; i < n; i++) {
        cin >> note >> fret; // 음과 프렛 입력 받음

        while(!m[note].empty()) {
            if(fret > m[note].top()) { // 1. 새로운 프렛이 이전 프렛보다 높은 경우
                press(note, fret, cnt);
                break;
            }
            else if(fret == m[note].top()) break; // 2. 새로운 프렛이 이전 프렛과 같은 경우
            depress(note, cnt); // 3. 새로운 프렛이 이전 프렛보다 낮은 경우
        }
        if(m[note].empty()) press(note, fret, cnt); // 4. 새로운 프렛을 아직 누르지 않은 경우
    }

    cout << cnt;
    return 0;
}