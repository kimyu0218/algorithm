#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> consult; // (first : 일자, second : 이익)

int max_benefit(int i, int n) { // 최대 수익 구하기 (i: 일자)
    // 1. i일 상담을 진행할 수 없는 경우
    if(i > n) return 0;
    if(i + consult[i].first  - 1 > n) return max_benefit(i+1, n);
    // 2. i일 상담을 진행할 수 있는 경우
    // 2-1. i일 상담을 진행하는 경우
    // 2-2. i일 상담을 진행하지 않는 경우
    return max(consult[i].second + max_benefit(i + consult[i].first, n), max_benefit(i+1, n));
}

int main() {
    int n;
    cin >> n;

    consult.assign(n+1, {0, 0});
    for(int i = 1; i <= n; i++) // 상담 정보 입력
        cin >> consult[i].first >> consult[i].second;

    cout << max_benefit(1, n);
    return 0;
}