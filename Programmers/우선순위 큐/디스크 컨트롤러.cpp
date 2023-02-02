#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator() (const vector<int> &a, const vector<int> &b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curr_time = 0;
    int total_time = 0;
    int job_idx = 0;
    int cnt = jobs.size();
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq; // 소요시간 오름차순
    sort(jobs.begin(), jobs.end()); // 요청시간 오름차순

    while(job_idx < cnt || !pq.empty()) {
        if(pq.empty()) {
            curr_time = jobs[job_idx][0];
            pq.push(jobs[job_idx++]);
        }

        vector<int> curr = pq.top();
        pq.pop();

        int delay = curr_time - curr[0]; // delay 시간
        total_time += (delay + curr[1]); // total 시간
        curr_time += curr[1];

        while(job_idx < cnt && jobs[job_idx][0] <= curr_time) { // 현재 시간까지 요청된 task push
            pq.push(jobs[job_idx++]);
        }
    }
    answer = total_time/cnt;
    return answer;
}