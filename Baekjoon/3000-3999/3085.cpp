#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 50;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
char board[SIZE][SIZE];

void swap(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

int count_horizontal(int r, int n) {
    int answer = 1;
    
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(board[r][i] == board[r][i - 1]) {
            cnt++;
            continue;
        }
        answer = max(answer, cnt);
        cnt = 1;
    }
    return max(answer, cnt);
}

int count_vertical(int c, int n) {
    int answer = 1;
    
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(board[i][c] == board[i - 1][c]) {
            cnt++;
            continue;
        }
        answer = max(answer, cnt);
        cnt = 1;
    }
    return max(answer, cnt);
}

int count_candy(int n) {
    int answer = 1;
    
    for(int i = 0; i < n; i++) {
        answer = max(answer, max(count_horizontal(i, n), count_vertical(i, n)));
        if(answer == n) {
            return n;
        }
    }
    return answer;
}

int solution(int n) {
    int answer = 1;
    
    for(int i = 0; i < n * n; i++) {
        int r = i / n;
        int c = i % n;
        
        for(int j = 0; j < 4; j++) {
            int nr = r + dr[j];
            int nc = c + dc[j];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == board[r][c]) {
                continue;
            }
            swap(board[r][c], board[nr][nc]);
            answer = max(answer, count_candy(n));
            if(answer == n) {
                return answer;
            }
            swap(board[r][c], board[nr][nc]);
        }
    }
    return answer;
}

int main() {
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << solution(n);
    return 0;
}
