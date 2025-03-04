#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 8 * 1e7 + 1;

int binarySearch(int k, int n, vector<vector<int>> &kss) {
    int answer = 0, diff = INF;
    vector<int> class12, class34; // 1반 + 2반, 3반 + 4반
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            class12.push_back(kss[0][i] + kss[1][j]);
            class34.push_back(kss[2][i] + kss[3][j]);
        }
    }
    sort(class12.begin(), class12.end());
    sort(class34.begin(), class34.end());

    int size = n * n;
    int left = 0, right = size-1;
    while(left < size && right >= 0) {
        int sum = class12[left] + class34[right]; // 4명의 몸무게 합
        int tmp = abs(sum - k);
        if(sum == k) { // k를 만들 수 있는 경우, 곧바로 답 리턴
            return k;
        }
        if(diff > tmp) { // 1. k에 더 가까운 값을 발견한 경우
            answer = sum;
            diff = tmp;
        }
        if(diff == tmp) { // 2. k에 가장 가까운 값인 경우, 더 작은 값으로 갱신
            answer = min(answer, sum);
        }
        if(sum > k) {
            right--;
        }
        else {
            left++;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, k, n;
    vector<vector<int>> kss;

    cin >> t;
    while(t--) { // 테스트케이스
        cin >> k >> n;
        kss.assign(4, vector<int> (n, 0));
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < n; j++) {
                cin >> kss[i][j];
            }
        }
        cout << binarySearch(k, n, kss) << '\n';
    }
    return 0;
}