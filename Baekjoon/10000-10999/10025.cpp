#include <iostream>

using namespace std;

const int MAX = 1000000;
int ice[MAX + 1];

int max_ice(int end_point, int k) {
    int sum = 0, window_size = 2 * k + 1;

    for(int i = 0; i < window_size; i++) { // 처음 윈도우
        if(i > end_point) break;
        sum += ice[i];
    }

    int ans = sum;
    for(int i = window_size; i <= end_point - k; i++) {
        sum -= ice[i - window_size];
        sum += ice[i];
        ans = max(ans, sum);
    }
    return ans;
}

int main() {
    int n, k, x, g, end_point = 0;
    cin >> n >> k;

    for(int i = 0; i < n; i++) { // 얼음 양동이 정보 입력
        cin >> g >> x;
        ice[x] = g;
        end_point = max(end_point, x);
    }

    cout << max_ice(end_point, k);
    return 0;
}