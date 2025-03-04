#include <iostream>

using namespace std;

const int SIZE = 8, MAX = 10000;
int arr[SIZE]; // 수열
int check[MAX+1]; // check[i] : i 등장 횟수

void backtracking(int cnt, int m) {
    if(cnt == m) { // 길이가 m인 수열 출력
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= MAX; i++) {
        if(check[i]) {
            check[i]--;
            arr[cnt] = i;
            backtracking(cnt+1, m);
            check[i]++;
        }
    }
}

int main() {
    int n, m, num;
    cin >> n >> m;

    while(n--) { // n개의 수 입력
        cin >> num;
        check[num]++;
    }

    backtracking(0, m);
    return 0;
}