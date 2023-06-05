#include <iostream>
#include <vector>

using namespace std;

// 가장 작은 조각의 길이의 최댓값이 k일 때, 몇 번을 자르는가
int cutRollCake(int k, int q, int m, int l, vector<int> &s) {
    int cut = 0, pre = 0;
    for(int i = 0; i < m; i++) {
        if(s[i]-pre >= k) {
            cut++;
            pre = s[i];
        }
    }
    // 마지막 조각 == 가장 작은 조각
    // 마지막 조각의 길이(l-pre)가 k보다 작은 경우, 한 번 덜 잘라야 함
    if(cut == q && l-pre < k) {
        return q-1;
    }
    return cut;
}

vector<int> binarySearch(int n, int m, int l, vector<int> &s, vector<int> &q) {
    vector<int> answer (n, 0);
    for(int i = 0; i < n; i++) {
        int left = 0, right = l;
        while(left <= right) {
            int mid = (left + right) / 2; // 가장 작은 조각의 길이 최댓값
            int cut = cutRollCake(mid, q[i], m, l, s);
            if(cut >= q[i]) { // 자르는 횟수를 만족한 경우, 최댓값 늘리기
                answer[i] = mid;
                left = mid + 1;
            }
            else { // 자르는 횟수를 만족하지 못한 경우, 최댓값 줄이기
                right = mid - 1;
            }
        }
    }
    return answer;
}

int main() {
    int n, m, l;
    vector<int> s, q;

    cin >> n >> m >> l;
    s.assign(m, 0);
    q.assign(n, 0);
    for(int i = 0; i < m; i++) { // 자를 수 있는 지점 입력
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) { // 자르는 횟수 입력
        cin >> q[i];
    }

    vector<int> answer = binarySearch(n, m, l, s, q);
    for(int i = 0; i < n; i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}