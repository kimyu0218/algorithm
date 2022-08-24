#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll MAX = 3000000000;
vector<int> liquid;

vector<int> find_liquid(int n) {
    vector<int> ans(3, 0);
    ll closest_mix = MAX;

    for(int i = 0; i < n-2; i++) {
        int left = i+1, right = n-1;

        while(left < right) {
            ll mix = (ll) liquid[i] + liquid[left] + liquid[right];
            if(abs(mix) < closest_mix) { // 0에 가장 가까운 혼합액 발견
                closest_mix = abs(mix);
                ans[0] = liquid[i];
                ans[1] = liquid[left];
                ans[2] = liquid[right];
                if(mix == 0) return ans; // (혼합액이 0이면 함수 종료)
            }
            if(mix < 0) left++; // 1. 혼합액이 0보다 작음 -> 특성값이 더 큰 용액 사용
            else right--; // 2. 혼합액이 0보다 큼 -> 특성값이 더 작은 용액 사용
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    liquid.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> liquid[i];
    sort(liquid.begin(), liquid.end());

    vector<int> ans = find_liquid(n);
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
    return 0;
}