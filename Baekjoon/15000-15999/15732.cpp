#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;

ll cntAcorns(int mid, int k, vector<ti> &rule) {
    ll cnt = 0;
    for(int i = 0; i < k; i++) {
        int a = get<0>(rule[i]);
        int b = get<1>(rule[i]);
        int c = get<2>(rule[i]);
        if(mid < a) { // 해당 규칙의 범위에 속하지 않음
            continue;
        }
        cnt += (min(b, mid)-a) / c + 1;
    }
    return cnt;
}

int binarySearch(int left, int right, int k, int d, vector<ti> &rule) {
    int answer = right;
    while(left <= right) {
        int mid = (left + right) / 2;
        ll cnt = cntAcorns(mid, k, rule);
        if(cnt >= d) { // 마지막 도토리를 넣을 수 있는 경우, 상자 번호 감소
            answer = mid;
            right = mid - 1;
        }
        else { // 마지막 도토리를 넣을 수 없는 경우, 상자 번호 증가
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, d, a, b, c;
    vector<ti> rule;
    vector<int> box;

    cin >> n >> k >> d;
    rule.assign(k, {0, 0, 0});
    for(int i = 0; i < k; i++) {
        cin >> a >> b >> c;
        rule[i] = {a, b, c};
    }

    cout << binarySearch(0, n, k, d, rule);
    return 0;
}