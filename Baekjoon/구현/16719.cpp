#include <iostream>

using namespace std;

const int SIZE = 100;
bool visited[SIZE]; // 방문 여부

int findPos(int left, int right, string &input) { // [left, right] 범위에서 사전순으로 가장 앞에 오는 문자 위치 찾기
    int mid = left;
    char tmp = 'Z' + 1;
    for(int i = left; i <= right; i++) {
        if(input[i] < tmp) {
            mid = i;
            tmp = input[i];
        }
    }
    return mid;
}

void solution(int left, int right, int n, string &input) {
    if(left > right) { // 기저 조건
        return;
    }
    int mid = findPos(left, right, input);
    visited[mid] = true; // 방문 체크
    for(int i = 0; i < n; i++) { // 방문한 문자 출력
        if(visited[i]) {
            cout << input[i];
        }
    }
    cout << '\n';
    solution(mid+1, right, n, input);
    solution(left, mid-1, n, input);
}

int main() {
    string input;
    cin >> input;

    solution(0, input.length()-1, input.length(), input);
    return 0;
}