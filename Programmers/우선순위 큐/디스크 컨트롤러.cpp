#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    int n = jobs.size();
    priority_queue<pi, vector<pi>, greater<>> pq;

    sort(jobs.begin(), jobs.end());

    int idx = 0;
    int curr_time = 0;

    while(idx < n || !pq.empty()) {
        if(pq.empty()) {
            curr_time = jobs[idx][0];
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }

        int s = pq.top().second;
        int t = pq.top().first;
        int w = curr_time - s;
        pq.pop();

        curr_time += t;
        answer += (w + t);

        while(idx < n && jobs[idx][0] <= curr_time) {
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }
    }
    return answer / n;
}