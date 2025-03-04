#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

bool cmp(const pi &p1, const pi &p2) { // 도수 오름차순
    return p1.second < p2.second;
}

struct cmp2 {
    bool operator () (const pi &p1, const pi &p2) { // 선호도 내림차순
        return p1.first < p2.first;
    }
};

typedef priority_queue<pi, vector<pi>, cmp2> pq;

vector<pi> beer; // (first : 선호도, second : 도수)

pq beerList(int level, int k) { // 간 레벨이 level일 때 마실 수 있는 맥주 후보
    pq list;
    for(int i = 0; i < k; i++) {
        if(beer[i].second > level) break;
        list.push(beer[i]);
    }
    return list;
}

int likeSum(int n, pq beerList) {
    int sum = 0;
    while(n--) {
        sum += beerList.top().first;
        beerList.pop();
    }
    return sum;
}

int binarySearch(ll left, ll right, int n, int m, int k) {
    int answer = -1;
    while(left <= right) {
        ll mid = (left + right) / 2; // 간 레벨
        pq beer_list = beerList(mid, k); // 간 레벨이 mid일 때 마실 수 있는 맥주 목록

        if(beer_list.size() < n) { // 1. n개 마시지 못함 -> 간 레벨 올리기
            left = mid + 1;
            continue;
        }

        int sum = likeSum(n, beer_list);
        if(sum >= m) { // 2. 선호도 만족 -> 간 레벨 낮추기
            answer = mid;
            right = mid - 1;
        }
        else { // 3. 선호도 불만족 -> 간 레벨 올리기
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    beer.assign(k, {0, 0});
    for(int i = 0; i < k; i++) // 맥주 선호도, 도수 입력
        cin >> beer[i].first >> beer[i].second;
    sort(beer.begin(), beer.end(), cmp);

    cout << binarySearch(beer[0].second, beer[k-1].second, n, m, k);
    return 0;
}