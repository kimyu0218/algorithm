#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v, sorted;

int main() {
    int n, tmp;
    cin >> n;

    while(n--) { // 좌표 입력
        cin >> tmp;
        sorted.push_back(tmp);
        v.push_back(tmp);
    }

    sort(sorted.begin(), sorted.end()); // 오름차순 정렬
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end()); // 중복 제거

    for(int & iter : v) {
        int order = lower_bound(sorted.begin(), sorted.end(), iter) - sorted.begin(); // bst 기반 탐색
        cout << order << ' ';
    }
    return 0;
}