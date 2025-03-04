#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

typedef pair<int, int> pi;

deque<pi> dq;

void move_left(int n) {
    for(int i = 0; i < n; i++) {
        dq.push_front(dq.back());
        dq.pop_back();
    }
}

void move_right(int n) {
    for(int i = 0; i < n; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
    }
}

vector<int> solution(vector<int> paper) {
    int n = paper.size();
    int bomb = 0;
    vector<int> result (n, 0);
    
    for(int i = 0; i < n; i++) {
        dq.push_back({i + 1, paper[i]});
    }
    
    while(bomb < n) {
        pi curr = dq.front();
        dq.pop_front();
        
        result[bomb++] = curr.first;
        if(curr.second < 0) {
            move_left(-curr.second);
        }
        else {
            move_right(curr.second - 1);
        }
    }
    return result;
}

int main() {
    int n;
    vector<int> paper;
    
    cin >> n;
    
    paper.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> paper[i];
    }

    vector<int> result = solution(paper);
    
    for(int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    return 0;
}