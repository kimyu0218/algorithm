#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2000000000;
vector<int> liquid; // 용액 특성 저장하는 배열

pair<int, int> find_liquid(int left, int right) { // (left: 가장 작은 특성, right: 가장 큰 특성)
    pair<int, int> ans;
    int closest_mix = MAX;

    while(left < right) { // (서로 다른 두 용액이므로 등호 포함하지 않음)
        int mix = liquid[left] + liquid[right];
        if(abs(mix) < closest_mix) { // 현재 혼합된 용액이 0에 더 가까운 경우, 답 갱신
            closest_mix = abs(mix);
            ans.first = liquid[left]; ans.second = liquid[right];
        }
        if(mix == 0) break; // (0보다 0에 더 가까울 수 없으므로 break)
        else if(mix < 0) left += 1; // 1. 혼합된 용액이 0보다 작은 경우, left 증가
        else right -= 1; // 2. 혼합된 용액이 0보다 큰 경우, right 증가
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    liquid.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> liquid[i];
    sort(liquid.begin(), liquid.end()); // 오름차순 정렬

    pair<int, int> answer = find_liquid(0, n-1);
    cout << answer.first << ' ' << answer.second;
    return 0;
}