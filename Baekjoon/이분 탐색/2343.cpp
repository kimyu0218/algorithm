#include <iostream>
#include <vector>

using namespace std;

int cnt_blue_ray(int k, int n, vector<int> lectures) {
    int answer = 1;
    int len = lectures[0];

    for(int i = 1; i < n; i++) {
        if(len + lectures[i] <= k) {
            len += lectures[i];
            continue;
        }
        len = lectures[i];
        answer++;
    }
    return answer;
}

int solution(int m, vector<int> lectures) {
    int answer = 0;

    int max_len = 0;
    int n = lectures.size();
    for(int i = 0; i < n; i++) {
        max_len = max(max_len, lectures[i]);
    }

    int left = max_len;
    int right = max_len * n;

    while(left <= right) {
        int mid = (left + right) / 2;
        int blue_ray = cnt_blue_ray(mid, n, lectures);

        if(blue_ray <= m) {
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
    vector<int> lectures;

    cin >> n >> m;

    lectures.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> lectures[i];
    }

    cout << solution(m, lectures);
    return 0;
}