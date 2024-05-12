#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int find_biggest(int n, vector<int> kettle) {
    int answer = 0;
    for(int i = 0; i < n ; i++) {
        answer = max(answer, kettle[i]);
    }
    return answer;
}

ll cnt_friends(int k, int n, vector<int> kettle) {
    ll answer = 0;
    for(int i = 0; i < n; i++) {
        answer += (kettle[i] / k);
    }
    return answer;
}

int solution(int k, vector<int> kettle) {
    int answer = 0;
    int n = kettle.size();

    ll left = 1;
    ll right = find_biggest(n, kettle);

    while(left <= right) {
        ll mid = (left + right) / 2;
        ll friends = cnt_friends(mid, n, kettle);

        if(friends >= k) {
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
    int n, k;
    vector<int> kettle;

    cin >> n >> k;

    kettle.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> kettle[i];
    }

    cout << solution(k, kettle);
    return 0;
}