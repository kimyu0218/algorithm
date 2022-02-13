#include <iostream>
#include <deque>

using namespace std;
deque<int> dq;

int findPos(int temp) { // 뽑아낼 위치 찾기
    for(int j = 0; j < dq.size(); j++)
        if(dq[j] == temp) return j;
    return -1;
}

void moveToLeft() { // 왼쪽으로 이동
    dq.push_back(dq.front());
    dq.pop_front();
}

void moveToRight() { // 오른쪽으로 이동
    dq.push_front(dq.back());
    dq.pop_back();
}

int secondOperation(int temp) { // 2번 연산
    int count = 0;
    while(true) {
        if(dq.front() == temp) { // 뽑아내기
            dq.pop_front(); return count;
        }
        count++; moveToLeft();
    }
}

int thirdOperation(int temp) { // 3번 연산
    int count = 0;
    while(true) {
        if(dq.front() == temp) { // 뽑아내기
            dq.pop_front(); return count;
        }
        count++; moveToRight();
    }
}

int main() {
    int n, m, temp, idx, count = 0;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) // 큐 초기화화
        dq.push_back(i);

    for(int i = 0; i < m; i++) {
        cin >> temp;
        idx = findPos(temp); // 뽑아낼 위치 찾기

        // (idx: 왼쪽에서부터 위치 / dq.size()-idx : 오른쪽에서부터 위치)
        if(idx < dq.size() - idx) count += secondOperation(temp);
        else count += thirdOperation(temp);
    }

    cout << count; // 연산 최솟값
    return 0;
}