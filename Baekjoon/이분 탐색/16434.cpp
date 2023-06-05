#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<int, int, int> ti;

bool killDragon(ll max_hp, ll atk, int n, vector<ti> &tah) { // MaxHP가 max_hp일 때, 용을 쓰러트릴 수 있는가
    ll cur_hp = max_hp;
    for(int i = 0; i < n; i++) {
        int t = get<0>(tah[i]);
        int a = get<1>(tah[i]);
        ll h = get<2>(tah[i]);

        if(t == 1) { // 1. 몬스터 발견
            ll cnt = (h / atk) + (h % atk > 0); // 몬스터 공격 횟수
            cur_hp -= a * (cnt-1); // 용사 공격 받음
            if(cur_hp <= 0) {
                return false;
            }
        }
        else if(t == 2) { // 2. 포션 발견
            cur_hp += h;
            cur_hp = min(cur_hp, max_hp); // MaxHP를 초과하는 경우, maxHP 재조정
            atk += a;
        }
    }
    return true;
}

ll binarySearch(ll left, ll right, int atk, int n, vector<ti> &tah) {
    ll answer = 0;
    while(left <= right) {
        ll mid = (left + right) / 2; // 용사의 최소 MaxHP
        bool flag = killDragon(mid, atk, n, tah);

        if(flag) { // 1. 드래곤을 죽인 경우, MaxHP 줄이기
            answer = mid;
            right = mid - 1;
        }
        else { // 2. 드래곤을 죽이지 못한 경우, MaxHP 늘리기
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, atk, t, a, h;
    ll max_hp = 0;
    vector<ti> tah;

    cin >> n >> atk;
    tah.assign(n, {0, 0, 0});
    for(int i = 0; i < n; i++) {
        cin >> t >> a >> h;
        tah[i] = {t, a, h};
        if(t == 1) {
            ll tmp = (ll) a * h;
            if(max_hp < tmp) {
                max_hp = tmp;
            }
        }
    }

    cout << binarySearch(1, max_hp * n, atk, n, tah);
    return 0;
}