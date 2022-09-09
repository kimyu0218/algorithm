#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<int> priorities, int location) {
    int answer = 0; // 인쇄 순서 카운트

    queue<pi> q; // 인쇄 대기 목록 큐 (first: 문서 번호, second: 중요도)
    for(int i = 0; i < priorities.size(); i++) // 대기 목록 초기화
        q.push({i, priorities[i]});

    while(!q.empty()) {
        // j 문서를 인쇄해볼까?
        int j = q.front().first;
        int value = q.front().second; q.pop();

        int high = -1; // (-1 : j문서보다 높은 중요도 없음)
        queue<pi> tmp = q;
        while(!tmp.empty()) {
            int doc = tmp.front().first;
            int doc_value = tmp.front().second; tmp.pop();
            if(doc_value > value) { // j문서보다 높은 중요도 발견
                high = doc;
                break;
            }
        }
        if(high == -1) { // 1. j문서보다 중요도 높은 문서 없음 -> 인쇄
            answer++;
            if(j == location) break;
        }
        else q.push({j, value}); // 2. j문서 대기 목록 제일 끝으로 보냄
    }
    return answer;
}