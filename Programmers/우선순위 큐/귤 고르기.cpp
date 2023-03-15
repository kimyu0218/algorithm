#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0, cnt = 0; // 귤 종류, 귤 개수 저장하는 변수
    map<int, int> m; // m[i] : 크기가 i인 귤의 개수
    priority_queue<int> pq; // 귤 개수 내림차순

    for(int i = 0; i < tangerine.size(); i++) { // 크기별 귤 개수 세기
        m[tangerine[i]]++;
    }

    for(auto iter = m.begin(); iter != m.end(); iter++) { // 귤 개수 내림차순으로 저장
        pq.push(iter->second);
    }

    while(!pq.empty()) {
        if(cnt >= k) { // 귤 k개 고름
            break;
        }
        cnt += pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}