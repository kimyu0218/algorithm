#include <iostream>

using namespace std;

const int MAX = 8;
int n, m;
bool check[MAX+1] = { false, }; // 사용 여부 저장하는 배열
int arr[MAX]; // 수열 저장하는 배열

void backtracking(int cnt) {
    if(cnt == m) { // 수열 길이가 m인 경우 수열 출력
        for(int i = 0; i < cnt; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    for(int i = 1; i <= n; i++) {
        if(check[i]) continue; // 이미 사용한 수 pass
        arr[cnt] = i; check[i] = true;
        backtracking(cnt+1);
        check[i] = false;
    }
}

int main() {
    cin >> n >> m;

    backtracking(0);
    return 0;
}