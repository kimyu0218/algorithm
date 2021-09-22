#include <iostream>
#include <stack>

using namespace std;
stack<int> melody[7]; // 기타 줄의 프렛 저장

int flick(int line, int flat) { // 손가락 튕기기
    melody[line].push(flat);
    return 1;
}

long long checkPreFlat(int line, int flat) { // 스택 검사
    long long count = 0;

    bool push = false; // 현재 음 push 여부 표시
    while(!melody[line].empty()) {
        if(melody[line].top() == flat) { // 같은 프렛인 경우 stop
            push = true;
            break;
        }
        else if(melody[line].top() < flat) {  // 더 높은 프렛인 경우
            count += flick(line, flat); // 손가락 튕기기
            push = true;
            break;
        }
        melody[line].pop(); count++; // 손가락 떼기
    }
    if(!push) count += flick(line, flat); // 현재 음 push 하지 않은 경우
    return count;
}

int main() {
    int n, p;
    long long count = 0;
    pair<int, int> temp;
    cin >> n >> p;

    while(n--) {
        cin >> temp.first >> temp.second;
        if(melody[temp.first].empty()) count += flick(temp.first, temp.second); // 스택이 비어있는 경우
        else count += checkPreFlat(temp.first, temp.second); // 스택 검사
    }
    cout << count;
    return 0;
}