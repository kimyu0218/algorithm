#include <iostream>
#include <vector>

using namespace std;

int cnt_range(int k, int n, vector<int> arr) {
    int answer = 1;

    int min_num = arr[0];
    int max_num = arr[0];
    for(int i = 1; i < n; i++) {
        max_num = max(max_num, arr[i]);
        min_num = min(min_num, arr[i]);

        int diff = max_num - min_num;
        if(diff <= k) {
            continue;
        }
        max_num = min_num = arr[i];
        answer++;
    }
    return answer;
}

int solution(int m, vector<int> arr) {
    int answer = 0;
    int n = arr.size();

    int left = 0;
    int right = 0;
    for(int i = 0; i < n; i++) {
        right = max(right, arr[i]);
    }

    while(left <= right) {
        int mid = (left + right) / 2;
        int range = cnt_range(mid, n, arr);

        if(range <= m) {
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
    vector<int> arr;

    cin >> n >> m;

    arr.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solution(m, arr);
    return 0;
}