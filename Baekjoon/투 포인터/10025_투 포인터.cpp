#include <iostream>

using namespace std;

const int MAX = 1000000;
int ice[2 * MAX + 1];

int max_ice(int end_point, int k) {
    int ans = 0, sum = 0;

    int left = 0, right = k, pos = 0; // (pos : 최적 위치, right와 항상 k만큼의 거리 유지)
    for(int i = 0; i <= k; i++) sum += ice[i]; // 0에서 얻을 수 있는 얼음양

    while(true) {
        ans = max(ans, sum); // 최댓값 갱신

        // 오른쪽으로 한 칸 이동
        pos++;
        if(pos - left > k)  { sum -= ice[left]; left++; }
        if(++right > end_point) break;
        sum += ice[right];
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