#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<pi> pillars) {
    int answer = 0;
    int n = pillars.size();

    sort(pillars.begin(), pillars.end());

    int left_l = pillars[0].first;
    int left_h = pillars[0].second;
    for(int i = 1; i < n; i++) {
        int l = pillars[i].first;
        int h = pillars[i].second;
        if(h >= left_h) {
            answer += (l - left_l) * left_h;
            left_l = l;
            left_h = h;
        }
    }
    answer += left_h;

    int right_l = pillars[n - 1].first;
    int right_h = pillars[n - 1].second;
    for(int i = n - 2; i >= 0; i--) {
        int l = pillars[i].first;
        int h = pillars[i].second;
        if(h > right_h) {
            answer += (right_l - l) * right_h;
            right_l = l;
            right_h = h;
        }
    }
    return answer;
}

int main() {
    int n;
    vector<pi> pillars;

    cin >> n;

    pillars.assign(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> pillars[i].first >> pillars[i].second;
    }

    cout << solution(pillars);
    return 0;
}