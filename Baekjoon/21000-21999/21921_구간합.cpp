#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x, hit, max = 0, cnt = 0;
    cin >> n >> x;

    vector<int> sum(n+1, 0); // i번째 일까지의 방문자 수 누적합 저장하는 배열
    for(int i = 1; i <= n; i++) {
        cin >> hit;
        sum[i] = sum[i-1] + hit;
    }

    for(int i = x; i <= n; i++) {
        int tmp = sum[i] - sum[i-x]; // i-x부터 x일간 방문자 수
        if(tmp > max) { // 최대 방문자 수 갱신
            max = tmp;
            cnt = 1;
        }
        else if(tmp == max) { // 최대 방문자 수가 같은 경우 기간 개수 갱신
            cnt++;
        }
    }

    if(max) cout << max << '\n' << cnt << '\n';
    else cout << "SAD"; // 최대 방문자 수가 0명인 경우
    return 0;
}