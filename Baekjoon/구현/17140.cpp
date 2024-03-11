#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e2;
typedef pair<int, int> pi;
int cnt[MAX];
int a[MAX][MAX];

void operationR(int &row, int &col) { // R 연산
    for(int i = 0; i < row; i++) {
        priority_queue<pi, vector<pi>, greater<>> pq; // (first : 빈도, second : 수)
        vector<int> freq (MAX+1, 0); // 빈도
        for(int j = 0; j < col; j++) {
            if(a[i][j] == 0) { // 0은 무시
                continue;
            }
            freq[a[i][j]]++;
            pq.push({freq[a[i][j]], a[i][j]});
        }
        int idx = 0;
        while(!pq.empty()) {
            int f = pq.top().first;
            int num = pq.top().second;
            pq.pop();

            if(freq[num] == f) { // 빈도수가 일치하는 경우, 배열에 추가
                a[i][idx++] = num;
                a[i][idx++] = f;
            }
            if(idx == MAX) {
                break;
            }
        }
        cnt[i] = idx;
    }

    for(int i = 0; i < row; i++) { // 열 크기 갱신
        col = max(col, cnt[i]);
    }
    for(int i = 0; i < row; i++) { // 나머지 0으로 채우기
        int start = cnt[i];
        for(int j = start; j < col; j++) {
            a[i][j] = 0;
        }
    }
}

void operationC(int &row, int &col) {
    for(int j = 0; j < col; j++) {
        priority_queue<pi, vector<pi>, greater<>> pq; // (first : 빈도, second : 수)
        vector<int> freq (MAX+1, 0); // 빈도
        for(int i = 0; i < row; i++) {
            if(a[i][j] == 0) { // 0은 무시
                continue;
            }
            freq[a[i][j]]++;
            pq.push({freq[a[i][j]], a[i][j]});
        }
        int idx = 0;
        while(!pq.empty()) {
            int f = pq.top().first;
            int num = pq.top().second;
            pq.pop();

            if(freq[num] == f) { // 빈도수가 일치하는 경우, 배열에 추가
                a[idx++][j] = num;
                a[idx++][j] = f;
            }
            if(idx == MAX) {
                break;
            }
        }
        cnt[j] = idx;
    }

    for(int j = 0; j < col; j++) { // 행 크기 갱신
        row = max(row, cnt[j]);
    }
    for(int j = 0; j < col; j++) { // 나머지 0으로 채우기
        int start = cnt[j];
        for(int i = start; i < row; i++) {
            a[i][j] = 0;
        }
    }
}

int solution(int r, int c, int k) {
    int time = 0;
    int row = 3, col = 3;
    while(true) {
        if(a[r-1][c-1] == k) { // k 만들기 성공
            return time;
        }
        if(++time > MAX) {
            return -1;
        }
        if(row >= col) { // R 연산
            operationR(row, col);
        }
        else { // C 연산
            operationC(row, col);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int r, c, k;

    cin >> r >> c >> k;
    for(int i = 0; i < 3; i++) { // 배열 입력
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    cout << solution(r, c, k);
    return 0;
}