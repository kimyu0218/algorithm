#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5 + 1;

int find_biggest(int n, vector<int> cost) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        answer = max(answer, cost[i]);
    }
    return answer;
}

int cnt_withdraw(int k, int n, vector<int> cost) {
    int answer = 0;
    int hyunwoo = 0;

    for(int i = 0; i < n; i++) {
        hyunwoo -= cost[i];
        if(hyunwoo < 0) {
            if(cost[i] > k) {
                return INF;
            }

            answer++;
            int q = cost[i] % k;
            if(q) {
                hyunwoo = (k - q);
            }
        }
    }
    return answer;
}

int solution(int m, vector<int> cost) {
    int answer = 0;
    int n = cost.size();

    int left = 0;
    int right = find_biggest(n, cost) * n;

    while(left <= right) {
        int mid = (left + right) / 2;
        int cnt = cnt_withdraw(mid, n, cost);

        if(cnt <= m) {
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
    vector<int> cost;

    cin >> n >> m;

    cost.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    cout << solution(m, cost);
    return 0;
}