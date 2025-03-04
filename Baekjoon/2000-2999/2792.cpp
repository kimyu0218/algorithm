#include <iostream>
#include <vector>

using namespace std;

int find_biggest(int n, vector<int> jewel) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        answer = max(answer, jewel[i]);
    }
    return answer;
}

int divide(int k, int n, vector<int> jewel) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        answer += (jewel[i] / k) + (jewel[i] % k > 0);
    }
    return answer;
}

int solution(int n, vector<int> jewel) {
    int answer = 0;
    int m = jewel.size();

    int left = 1;
    int right = find_biggest(m, jewel);

    while(left <= right) {
        int mid = (left + right) / 2;
        int cnt = divide(mid, m, jewel);

        if(cnt <= n) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    int n, m;
    vector<int> jewel;

    cin >> n >> m;

    jewel.assign(m, 0);
    for(int i = 0; i < m; i++) {
        cin >> jewel[i];
    }

    cout << solution(n, jewel);
    return 0;
}