#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
const int INF = 1e9 * 2;

pi binarySearch(int n, vector<int> &liquid) { // 이분 탐색
    int left = 0, right = n-1;
    int close_sum = INF;
    pi answer;

    while(left < right) {
        int sum = liquid[left] + liquid[right]; // left와 right 용액을 섞은 혼합액의 특성값

        if(sum == 0) { // 특성값이 0인 경우, 곧바로 답 리턴
            return {liquid[left], liquid[right]};
        }
        if(abs(sum) < close_sum) { // 0에 가장 가까운 용액 발견한 경우, 답 갱신
            close_sum = abs(sum);
            answer = {liquid[left], liquid[right]};
        }
        if(sum > 0) { // 특성값이 0보다 큰 경우, right 감소
            right--;
        }
        else { // 특성 값이 0보다 큰 경우, left 증가
            left++;
        }
    }
    return answer;
}

int main() {
    int n;
    vector<int> liquid;

    cin >> n;
    liquid.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    sort(liquid.begin(), liquid.end()); // 오름차순 정렬
    pi answer = binarySearch(n, liquid);
    cout << answer.first << ' ' << answer.second;
    return 0;
}