#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    int n = score.size();
    vector<int> answer (n, 0);
    priority_queue<int, vector<int>, greater<>> pq;

    for(int i = 0; i < n; i++) {
        pq.push(score[i]);
        if(pq.size() > k) {
            pq.pop();
        }
        answer[i] = pq.top();
    }
    return answer;
}