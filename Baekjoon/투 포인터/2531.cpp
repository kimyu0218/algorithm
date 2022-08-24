#include <iostream>
#include <vector>

using namespace std;

vector<int> sushi;

void add_sushi(int &cnt, int sushi_no, vector<int> &choice) { // 스시 먹음
    choice[sushi_no]++;
    if(choice[sushi_no] == 1) cnt++;
}

void remove_sushi(int &cnt, int sushi_no, vector<int> &choice) { // 스시 먹지 않음
    choice[sushi_no]--;
    if(!choice[sushi_no]) cnt--;
}

int max_sushi(int n, int d, int k, int c) {
    int ans = 0, cnt = 0; // (cnt : 스시 종류 개수 저장하는 변수)
    int left = 0, right = k-1; // 투 포인터 (left : 시작 위치, right : 끝 위치)

    vector<int> choice(d+1, 0); // 손님이 고른 초밥 저장
    for(int i = 0; i < k; i++) add_sushi(cnt, sushi[i], choice); // k개 초밥 연속으로 먹기
    add_sushi(cnt, c, choice); // 쿠폰 사용

    while(true) {
        ans = max(ans, cnt);
        // 한 칸씩 이동 (left 초밥 제외, right 초밥 추가)
        remove_sushi(cnt, sushi[left], choice);
        left = (left + 1) % n; right = (right + 1) % n;
        add_sushi(cnt, sushi[right], choice);
        if(!left) break; // 한 바퀴 다 돌은 경우
    }
    return ans;
}

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    sushi.assign(n, 0);
    for(int i = 0; i < n; i++) // 초밥 종류 입력
        cin >> sushi[i];

    cout << max_sushi(n, d, k, c);
    return 0;
}