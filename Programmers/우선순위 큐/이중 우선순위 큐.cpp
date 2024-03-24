#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<char, int> parse_operation(string operation) {
    return {operation[0], stoi(operation.substr(2, operation.length() - 2))};
}

void sync(priority_queue<int, vector<int>, greater<>> &min_pq, priority_queue<int> &max_pq) {
    while(!min_pq.empty() && !max_pq.empty() && max_pq.top() < min_pq.top()) {
        max_pq.pop();
        min_pq.pop();
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int, vector<int>, greater<>> min_pq;
    priority_queue<int> max_pq;

    for(int i = 0; i < operations.size(); i++) {
        pair<char, int> op = parse_operation(operations[i]);

        if(op.first == 'I') {
            max_pq.push(op.second);
            min_pq.push(op.second);
            continue;
        }

        if(min_pq.empty()) {
            continue;
        }

        if(op.second == -1) {
            min_pq.pop();
        }
        else {
            max_pq.pop();
        }
        sync(min_pq, max_pq);
    }

    if(min_pq.empty()) {
        return {0, 0};
    }
    return {max_pq.top(), min_pq.top()};
}