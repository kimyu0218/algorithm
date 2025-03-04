#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt_cousin(int k, int n, vector<int> l) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        answer += l[i] / k;
    }
    return answer;
}

int solution(int m, vector<int> l) {
    int answer = 0;
    int n = l.size();

    sort(l.begin(), l.end());

    int left = 1;
    int right = l[n - 1];

    while(left <= right) {
        int mid = (left + right) / 2;
        int cousin = cnt_cousin(mid, n, l);

        if(cousin >= m) {
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
    int m, n;
    vector<int> l;

    cin >> m >> n;

    l.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }

    cout << solution(m, l);
    return 0;
}