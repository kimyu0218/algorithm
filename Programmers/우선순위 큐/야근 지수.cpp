#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;

ll solution(int n, vector<int> works) {
    ll answer = 0;
    priority_queue<int> pq;

    for(int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }

    while(n-- && !pq.empty()) {
        int top = pq.top();
        pq.pop();
        if(top == 0) {
            break;
        }
        pq.push(top - 1);
    }

    while(!pq.empty()) {
        answer += pow(pq.top(), 2);
        pq.pop();
    }
    return answer;
}