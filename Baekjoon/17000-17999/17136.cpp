#include <iostream>

using namespace std;

const int PAPER_SIZE = 10;
const int MAX_SIZE = 5, MAX_CNT = 5;
int answer = -1;
int paper[PAPER_SIZE][PAPER_SIZE]; // 종이
int colored[MAX_SIZE + 1] = {0, }; // 색종이별 개수

bool canCover(int sr, int sc, int size) {
    if(sr + size > PAPER_SIZE || sc + size > PAPER_SIZE) {
        return false;
    }
    for(int i = sr; i < sr + size; i++) {
        for(int j = sc; j < sc + size; j++) {
            if(!paper[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void attachDetach(int sr, int sc, int size) { // 색종이 붙이기/떼어내기
    for(int i = sr; i < sr + size; i++) {
        for(int j = sc; j < sc + size; j++) {
            paper[i][j] = !paper[i][j];
        }
    }
}

void backtracking(int idx, int cnt, int remain) {
    if(answer != -1 && cnt >= answer) { // 더 적은 색종이로 붙이는 경우 존재 -> 더 이상 탐색 x
        return;
    }
    if(!remain) { // 색종이 다 붙인 경우
        answer = cnt;
        return;
    }
    if(idx == PAPER_SIZE * PAPER_SIZE) { // 기저조건
        return;
    }
    int row = idx / PAPER_SIZE;
    int col = idx % PAPER_SIZE;
    if(paper[row][col]) { // 색종이 붙여야 하는 경우
        for(int i = MAX_SIZE; i >= 1; i--) {
            if(canCover(row, col, i) && colored[i] < MAX_CNT) { // i x i 크기의 색종이 붙이기
                attachDetach(row, col, i);
                colored[i]++;
                backtracking(idx + 1, cnt + 1, remain - i * i);
                colored[i]--;
                attachDetach(row, col, i);
            }
        }
    }
    else {
        backtracking(idx + 1, cnt, remain);
    }
}

int main() {
    int one = 0;
    for(int i = 0; i < PAPER_SIZE; i++) { // 종이 정보 입력
        for(int j = 0; j < PAPER_SIZE; j++) {
            cin >> paper[i][j];
            if(paper[i][j]) {
                one++;
            }
        }
    }
    backtracking(0, 0, one);
    cout << answer;
    return 0;
}