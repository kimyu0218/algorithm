#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int find_biggest(int n, vector<int> len) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        answer = max(answer, len[i]);
    }
    return answer;
}

ll cnt_line(int k, int n, vector<int> len) {
    ll answer = 0;
    for(int i = 0; i < n; i++) {
        answer += (len[i] / k);
    }
    return answer;
}

int solution(int n, vector<int> len) {
    int answer = 0;
    int m = len.size();

    ll left = 1;
    ll right = find_biggest(m, len);

    while(left <= right) {
        ll mid = (left + right) / 2;
        ll line = cnt_line(mid, m, len);

        if(line >= n) {
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
    int k, n;
    vector<int> len;

    cin >> k >> n;

    len.assign(k, 0);
    for(int i = 0; i < k; i++) {
        cin >> len[i];
    }

    cout << solution(n, len);
    return 0;
}