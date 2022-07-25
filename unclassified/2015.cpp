#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> preSum; // 부분합 저장하는 배열
map<int, long long> m;

long long partialSum(int k, int n) { // 부분합 찾기
    long long result = 0;
    for(int i = 1; i <= n; i++) {
        if(preSum[i] == k) result++; // 부분합이 k인 경우
        result += m[preSum[i] - k];  // preSum[i] - preSum[j] == k
        m[preSum[i]]++;
    }
    return result;
}

int main() {
    int n, k, temp;
    cin >> n >> k;

    preSum.assign(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        preSum[i] = preSum[i-1] + temp;
    }
    cout << partialSum(k, n);
    return 0;
}