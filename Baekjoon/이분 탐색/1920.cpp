#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a;

bool binary_search(int left, int right, int test) { // 이분 탐색
    while(left <= right) {
        int mid = (left + right) / 2;
        if(test == a[mid]) return true;
        if(test > a[mid]) left = mid + 1;
        if(test < a[mid]) right = mid - 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, test;
    cin >> n;

    a.assign(n, 0);
    for(int i = 0; i < n; i++) // n개의 정수 입력
        cin >> a[i];
    sort(a.begin(), a.end()); // 오름차순 정렬

    cin >> m;
    while(m--) {
        cin >> test;
        cout << binary_search(0, n-1, test) << '\n';
    }
    return 0;
}