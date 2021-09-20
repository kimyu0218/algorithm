#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, height;
    cin >> n;

    stack<pair<int, int>> top; // (수신탑 높이, 수신탑 위치)
    for(int i = 0; i < n; i++) {
        cin >> height;
        while(!top.empty()) {
            if(height < top.top().first) { // 수신탑 발견
                cout << top.top().second << ' ';
                break;
            }
            top.pop(); // 낮은 탑 버리기
        }
        if(top.empty()) cout << 0 << ' ';
        top.push({height, i+1}); // 수신탑 정보 저장
    }
    return 0;
}