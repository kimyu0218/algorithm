#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int cnt_stick(string bracket) {
    int cnt = 0; // 쇠막대기 개수
    vector<int> lazer; // 레이저 위치 저장

    stack<int> s; // 여는 괄호 위치 정보 저장
    for(int i = 0; i < bracket.length(); i++) {
        if(bracket[i] == '(') s.push(i); // 1. 여는 괄호 무조건 push
        else if(bracket[i] == ')' && bracket[i-1] == '(') { // 2. 레이저 발견
            lazer.push_back(i); s.pop(); // 레이저 위치 저장 및 레이저 여는 괄호 제거
        }
        else if(bracket[i] == ')') { // 3. 쇠막대기 오른쪽 끝점 발견
            int start_idx = s.top(); s.pop(); // (start_idx : 왼쪽 끝점)

            int cut = 0; // (start_idx, i) 사이 자르는 개수 세기
            for(int j = 0; j < lazer.size(); j++) {
                if(lazer[j] > start_idx && lazer[j] < i) cut++;
            }
            cnt += (cut + 1); // 쇠막대기 수 세기
        }
    }
    return cnt;
}

int main() {
    string bracket;
    cin >> bracket;

    cout << cnt_stick(bracket);
    return 0;
}