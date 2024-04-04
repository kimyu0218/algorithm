#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt_modem(int k, int n, vector<int> x) {
    int answer = 1;
    int pre = x[0];

    for(int i = 1; i < n; i++) {
        if(x[i] - pre < k) {
            continue;
        }
        pre = x[i];
        answer++;
    }
    return answer;
}

int solution(int c, vector<int> x) {
    int answer = 0;
    int n = x.size();

    sort(x.begin(), x.end());

    int left = 1;
    int right = x[n - 1] - x[0];

    while(left <= right) {
        int mid = (left + right) / 2;
        int modem = cnt_modem(mid, n, x);

        if(modem >= c) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return answer;
}

int main() {
    int n, c;
    vector<int> x;

    cin >> n >> c;

    x.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << solution(c, x);
    return 0;
}