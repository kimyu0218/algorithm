#include <iostream>
#include <vector>

using namespace std;

int find_biggest(int n, vector<int> cost) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        answer = max(answer, cost[i]);
    }
    return answer;
}

int get_sum(int k, int n, vector<int> cost) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        answer += min(k, cost[i]);
    }
    return answer;
}

int solution(int m, vector<int> cost) {
    int answer = 0;
    int n = cost.size();

    int left = 1;
    int right = find_biggest(n, cost);

    while(left <= right) {
        int mid = (left + right) / 2;
        int sum = get_sum(mid, n, cost);

        if(sum <= m) {
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
    int n, m;
    vector<int> cost;

    cin >> n;

    cost.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    cin >> m;

    cout << solution(m, cost);
    return 0;
}