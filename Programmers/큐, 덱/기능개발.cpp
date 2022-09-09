#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int cnt = progresses.size(); // 작업 개수
    vector<int> date(cnt, 0); // 남은 작업량을 개발하는 데 걸리는 시간
    for(int i = 0; i < cnt; i++) {
        int remain = 100 - progresses[i]; // 남은 작업량
        date[i] = remain / speeds[i];
        if(remain % speeds[i]) date[i]++;
    }

    queue<int> q; // front가 가장 큰 수 가리킴
    for(int i = 0; i < cnt; i++) {
        if(!q.empty() && date[i] > q.front()) {
            answer.push_back(q.size()); // i-1까지만 같이 배포
            while(!q.empty()) q.pop();
        }
        q.push(date[i]);
    }
    if(!q.empty()) answer.push_back(q.size());
    return answer;
}