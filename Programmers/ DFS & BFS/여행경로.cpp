#include <string>
#include <vector>
#include <set>

using namespace std;

bool stop = false;
vector<string> result; // 공항 경로 저장
set<int> visited; // 사용한 티켓 번호 저장

void bfs(string src, int n, vector<vector<string>> tickets, vector<string> route) {
    if(stop) return; // 이미 경로 찾은 경우 더 이상 탐색하지 않음
    route.push_back(src);

    if(visited.size() == n) {
        result = route; stop = true;
        return;
    }

    set<pair<string, int>> dests; // (first: 시작 공항, second: 티켓 번호)
    for(int i = 0; i < n; i++) {
        if(visited.find(i) != visited.end()) continue;
        if(src == tickets[i][0]) dests.insert({tickets[i][1], i}); // 목적지 추가
    }

    for(auto iter = dests.begin(); iter != dests.end(); iter++) { // 사전순으로 먼저 탐색
        visited.insert(iter->second); // 티켓 사용 완료
        bfs(iter->first, n, tickets, route);
        visited.erase(iter->second); // 티켓 사용 취소
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int n = tickets.size();
    bfs("ICN", n, tickets, {}); // ICN 공항에서 출발
    return result;
}