#include <iostream>

using namespace std;

int solution(int a, int b, int c, int x, int y) {
    int answer = a * x + b * y;
    int z = max(x, y);

    for(int i = 1; i <= z; i++) {
        int remain_x = x - i;
        int remain_y = y - i;
        int cmp = c * i * 2;
        if(remain_x > 0) {
            cmp += a * remain_x;
        }
        if(remain_y > 0) {
            cmp += b * remain_y;
        }
        answer = min(answer, cmp);
    }
    return answer;
}

int main() {
    int a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;

    cout << solution(a, b, c, x, y);
    return 0;
}