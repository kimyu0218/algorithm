#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<int> ride; // 놀이기구 운행 시간과 번호 저장하는 배열

// k분동안 놀이기구를 탈 수 있는 인원 구하기
ll cnt_people(ll k, int m) {
    ll cnt = m;
    for(int i = 1; i <= m; i++)
        cnt += k / ride[i];
    return cnt;
}

// n명이 모두 타는데 소요되는 최소 시간 구하기
ll time_required(ll left, ll right, int m, int n) {
    ll ans = 0;
    while(left <= right) {
        ll mid = (left + right) / 2;
        ll people = cnt_people(mid, m);

        if(people < n) left = mid + 1; // 1. n번째 사람 타지 못함 -> 소요시간 늘리기
        else { // 2. n번째 사람 탈 수 있음 -> 소요시간 줄이기
            ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}

int ride_no(int m, int n) {
    ll time = time_required(0, (ll) ride[1] * n, m, n);
    ll people = cnt_people(time, m);

    int no = 0;
    for(int i = m; i >= 1; i--) {
        if(time % ride[i] == 0) { // 놀이기구 탑승 가능
            if(people == n) { no = i; break; }
            people--;
        }
    }
    return no;
}

int main() {
    int n, m;
    cin >> n >> m;

    ride.assign(m+1, 0);
    for(int i = 1; i <= m; i++)  // 놀이기구 정보 입력
        cin >> ride[i];

    if(n <= m) cout << n;
    else cout << ride_no(m, n);
    return 0;
}