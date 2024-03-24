#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<int> priorities, int location) {
    int answer = 1;

    queue<pi> q;
    priority_queue<int> pq;

    int n = priorities.size();
    for(int i = 0; i < n; i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    while(!q.empty()) {
        int priority = q.front().first;
        int pid = q.front().second;
        q.pop();

        if(priority != pq.top()) {
            q.push({priority, pid});
            continue;
        }

        if(pid == location) {
            return answer;
        }
        pq.pop();
        answer++;
    }
}