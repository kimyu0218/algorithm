#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, int> count_tangerine(vector<int> tangerine) {
    int n = tangerine.size();
    map<int, int> m;

    for(int i = 0; i < n; i++) {
        m[tangerine[i]]++;
    }
    return m;
}

priority_queue<int> sort_by_count(map<int, int> m) {
    priority_queue<int> pq;

    for(auto iter = m.begin(); iter != m.end(); iter++) {
        pq.push(iter->second);
    }
    return pq;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m = count_tangerine(tangerine);
    priority_queue<int> pq = sort_by_count(m);

    int cnt = 0;
    while(cnt < k) {
        cnt += pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}