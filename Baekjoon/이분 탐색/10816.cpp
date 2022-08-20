#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> card;

// 1. test가 처음으로 나오는 위치 반환
int lower_bound(int left, int right, int test) {
    while(left <= right) {
        int mid = (left + right) / 2;
        if(test <= card[mid]) right = mid - 1;
        if(test > card[mid]) left = mid + 1;
    }
    return right + 1;
}

// 2. test를 초과하는 수가 처음으로 나오는 위치 반환
int upper_bound(int left, int right, int test) {
    while(left <= right) {
        int mid = (left + right) / 2;
        if(test < card[mid]) right = mid - 1;
        if(test >= card[mid]) left = mid + 1;
    }
    return right + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, test;
    cin >> n;

    card.assign(n, 0);
    for(int i = 0; i < n; i++) // 카드 입력
        cin >> card[i];
    sort(card.begin(), card.end()); // 오름차순 정렬

    cin >> m;
    while(m--) {
        cin >> test;
        cout << upper_bound(0, n-1, test) - lower_bound(0, n-1, test) << ' ';
    }
    return 0;
}