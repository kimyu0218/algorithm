#include <iostream>

using namespace std;

const int MAX = 8;
int n, m;
int arr[MAX]; // 수열 저장하는 배열
bool check[MAX+1] = { false, }; // 사용 여부 저장하는 배열

void backtracking(int start, int cnt) {
    if(cnt == m) { // 수열 길이가 m인 경우 수열 출력
        for(int i = 0; i < cnt; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    for(int i = start; i <= n; i++) {
        if(check[i]) continue; // 이미 사용한 수 pass
        arr[cnt] = i; check[i] = true;
        backtracking(i+1, cnt+1);
        check[i] = false;
    }
}

int main() {
    cin >> n >> m;

    backtracking(1, 0);
    return 0;
}