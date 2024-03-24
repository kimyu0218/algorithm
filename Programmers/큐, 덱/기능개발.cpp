#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int n = progresses.size();

    vector<int> day(n, 0);
    for(int i = 0; i < n; i++) {
        int remain = 100 - progresses[i];
        day[i] = (remain / speeds[i]) + (remain % speeds[i] > 0);
    }

    int idx = 0;
    queue<int> q;
    q.push(day[idx++]);

    while(idx < n) {
        int deploy_date = q.front();

        if(day[idx] > deploy_date) {
            answer.push_back(q.size());
            while(!q.empty()) {
                q.pop();
            }
        }
        q.push(day[idx++]);
    }

    answer.push_back(q.size());
    return answer;
}