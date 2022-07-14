#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, height;
    cin >> n;

    stack<pair<int, int>> s; // (first : 탑 높이, second : 탑 순서)
    for(int i = 1; i <= n; i++){
        cin >> height; // 탑 높이 입력 받기

        while(!s.empty()) {
            // (현재 탑보다 이전 순서의 탑이 높은 경우에 수신 가능)
            if(height <= s.top().first) { // 1. 수신 가능
                cout << s.top().second << ' ';
                break;
            }
            s.pop(); // 2. 수신 불가능
        }
        if(s.empty()) cout << 0 << ' ';
        s.push({height, i});
    }
    return 0;
}