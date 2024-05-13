#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int find_biggest(int n, vector<int> l) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        answer = max(answer, l[i]);
    }
    return answer;
}

ll cnt_chicken(int k, int n, vector<int> l) {
    ll answer = 0;
    for(int i = 0; i < n; i++) {
        answer += (l[i] / k);
    }
    return answer;
}

ll solution(int c, vector<int> l) {
    ll answer = 0;
    int len = 0;
    int s = l.size();

    int left = 1;
    int right = find_biggest(s, l);

    while(left <= right) {
        int mid = (left + right) / 2;
        ll chicken = cnt_chicken(mid, s, l);

        if(chicken >= c) {
            len = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    for(int i = 0; i < s; i++) {
        answer += l[i];
    }
    return answer - (ll) len * c;
}

int main() {
    int s, c;
    vector<int> l;

    cin >> s >> c;

    l.assign(s, 0);
    for(int i = 0; i < s; i++) {
        cin >> l[i];
    }

    cout << solution(c, l);
    return 0;
}