#include <iostream>
#include <set>

using namespace std;

const int MAX = 7;
int n, m;
int arr[MAX+1]; // 수열 저장히는 배열
set<int> s;

void backtracking(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < cnt; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(auto iter = s.begin(); iter != s.end(); iter++) {
        arr[cnt] = *iter; // 수열에 넣기
        backtracking(cnt+1);
    }
}

int main() {
    cin >> n >> m;

    int num;
    for(int i = 0; i < n; i++) {// 수 입력받기
        cin >> num;
        s.insert(num);
    }

    backtracking(0);
    return 0;
}