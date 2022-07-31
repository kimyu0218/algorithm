#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> a, b;

void change(int row, int col) { // 3x3 부분 행렬 모든 원소 뒤집기
    for(int i = row; i < row+3; i++) {
        for(int j = col; j < col+3; j++) {
            if(a[i][j] == '1') a[i][j] = '0';
            else a[i][j] = '1';
        }
    }
}

bool check(int n, int m) { // 행렬 A와 행렬 B가 같은가
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

int compute(int n, int m) {
    int cnt = 0;
    for(int i = 0; i <= n-3; i++) {
        for(int j = 0; j <= m-3; j++) {
            if(a[i][j] != b[i][j]) { // 원소가 다른 경우 뒤집기
                change(i, j);
                cnt++;
            }
        }
    }
    if(!check(n, m)) return -1; // 행렬 A와 행렬 B가 다른 경우
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;

    string tmp;
    a.assign(n, vector<char> (m, 0));
    b.assign(n, vector<char> (m, 0));

    // 행렬 A 입력
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        for(int j = 0; j < m; j++)
            a[i][j] = tmp[j];
    }

    // 행렬 B 입력
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        for(int j = 0; j < m; j++)
            b[i][j] = tmp[j];
    }

    cout << compute(n, m);
    return 0;
}