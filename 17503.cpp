#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
vector<pi> beer;

bool cmp(const pi &p1, const pi &p2) {
    if(p1.first != p2.first) return p1.first > p2.first;
    return p1.second < p2.second;
}

bool drinkBeer(int level, int k, int n, int m) {
    int cnt = 0, like = 0;
    for(int i = 0; i < k; i++) {
        if(beer[i].second <= level) {
            cnt++;
            like += beer[i].first;
        }
        if(cnt == n) break;
    }
    if(like >= m) return true;
    return false;
}

int binarySearch(int left, int right, int n, int m, int k) {
    int answer = -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        bool satisfy = drinkBeer(mid, k, n, m);

        if(satisfy) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k, max_limit = 0;
    cin >> n >> m >> k;

    beer.assign(k, {0, 0});
    for(int i = 0; i < k; i++) { // 맥주 선호도, 도수 입력
        cin >> beer[i].first >> beer[i].second;
        max_limit = max(max_limit, beer[i].second);
    }
    sort(beer.begin(), beer.end(), cmp);

    cout << binarySearch(1, max_limit, n, m, k);
    return 0;
}