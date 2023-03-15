#include <string>
#include <vector>
#include <queue>

using namespace std;

// 최대 힙과 최소 힙 싱크 맞추기
void sync(priority_queue<int> &max_pq, priority_queue<int, vector<int>, greater<>> &min_pq) {
    // max_top() < min_top() : 최소 힙에서 삭제된 값이 최대 힙에 들어있음
    while(!max_pq.empty() && max_pq.top() < min_pq.top()) {
        max_pq.pop();
    }
    // min_top() > max_top() : 최대 힙에서 삭제된 값이 최소 힙에 들어있음
    while(!min_pq.empty() && min_pq.top() > max_pq.top()) {
        min_pq.pop();
    }
}

vector<int> solution(vector<string> operations) {
    priority_queue<int> max_pq; // 최대 힙
    priority_queue<int, vector<int>, greater<>> min_pq; // 최소 힙

    for(int i = 0; i < operations.size(); i++) {
        char op = operations[i][0];
        int num = stoi(operations[i].erase(0,2)); // (숫자만 남기기)

        if(op == 'I') { // I 숫자 : 숫자 삽입
            max_pq.push(num);
            min_pq.push(num);
        }
        // D 숫자 : 숫자 삭제
        else if(min_pq.empty()) { // 힙이 비어있는 경우 삭제 불가
            continue;
        }
        else if(num == 1) { // 최댓값 삭제
            max_pq.pop();
            sync(max_pq, min_pq);
        }
        else { // 최솟값 삭제
            min_pq.pop();
            sync(max_pq, min_pq);
        }
    }

    if(min_pq.empty()) { // 큐가 비어있는 경우
        return {0, 0};
    }
    return {max_pq.top(), min_pq.top()};
}