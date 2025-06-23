#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    int n = progresses.size();
    for(int i = 0; i < n; i++) {
        int speed = speeds[i];
        int r = 100 - progresses[i];
        int d_day = (r / speed) + (r % speed != 0);

        if(!q.empty() && d_day > q.front()) {
            answer.push_back(q.size());

            while(!q.empty()) {
                q.pop();
            }
        }
        q.push(d_day);
    }
    answer.push_back(q.size());
    return answer;
}