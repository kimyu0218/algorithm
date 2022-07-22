#include <iostream>

using namespace std;

const int MAX = 20;
int n, result = MAX * MAX * 100;
int s[MAX][MAX] = { 0, }; // 능력치 저장하는 배열
bool check[MAX] = { false, }; // 링크팀 분배 여부 저장하는 배열

int compute() { // 능력치 차 계산
    int link = 0, start = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(check[i] && check[j]) link += (s[i][j] + s[j][i]); // i와 j가 모두 링크 팀인 경우
            else if(!check[i] && !check[j]) start += (s[i][j] + s[j][i]); // i와 j가 모두 스타트 팀인 경우
        }
    }
    return abs(link - start);
}

void backtracking(int idx) {
    if(idx == n) { // 더 이상 탐색할 인원이 없는 경우
        result = min(result, compute()); // 능력치차 갱신
        return;
    }

    for(int i = idx; i < n; i++) {
        check[i] = true; // 링크팀 배정
        backtracking(i+1);
        check[i] = false; // 스타트팀 배정
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) { // 능력치 입력받기
        for(int j = 0; j < n; j++)
            cin >> s[i][j];
    }

    backtracking(0);
    cout << result;
    return 0;
}