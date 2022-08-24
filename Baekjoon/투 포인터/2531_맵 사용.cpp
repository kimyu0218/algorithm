#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> sushi;

int max_sushi(int n, int k, int c) {
    int ans = 0, left = 0, right = k-1;

    map<int, int> choice; // 손님이 고른 초밥 저장
    for(int i = 0; i < k; i++) choice[sushi[i]]++; // k개 초밥 연속으로 먹기
    choice[c]++; // 쿠폰 사용

    while(true) {
        ans = max(ans, (int) choice.size());
        // 한 칸씩 이동 (left 초밥 제외, right 초밥 추가)
        if(--choice[sushi[left]] == 0) choice.erase(sushi[left]);
        left = (left + 1) % n; right = (right + 1) % n;
        choice[sushi[right]]++;
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

    cout << max_sushi(n, k, c);
    return 0;
}