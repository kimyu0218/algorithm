#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

vector<string> topologicalSort(int n, set<string> items, unordered_map<string, int> &indegree, unordered_map<string, vector<string>> &graph) {
    vector<string> result; // 구매 목록 저장
    priority_queue<string, vector<string>, greater<>> pq, tmp; // 사전순

    for(auto iter = items.begin(); iter != items.end(); iter++) {
        if(!indegree[*iter]) { // 진입 차수가 0인 경우
            pq.push(*iter);
        }
    }

    while(!pq.empty()) {
        string node = pq.top(); pq.pop();
        result.push_back(node);

        for(int i = 0; i < graph[node].size(); i++) { // 후속 아이템 탐색
            string next = graph[node][i];
            indegree[next]--;
            if(!indegree[next]) { // 진입 차수가 0인 경우
                tmp.push(next);
            }
        }
        if(pq.empty() && !tmp.empty()) { // 진입 차수가 0인 정점 탐색 완료
            swap(pq, tmp);
        }
    }

    if(result.size() != n) { // 모든 아이템을 구매할 수 없는 경우
        result = {"-1"};
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    unordered_map<string, int> indegree; // 진입 차수
    unordered_map<string, vector<string>> graph;
    set<string> items; // 아이템 저장

    string a, b;
    while(n--) { // 아이템 입력
        cin >> a >> b;
        indegree[b]++;
        graph[a].push_back(b);
        items.insert(a);
        items.insert(b);
    }

    vector<string> result = topologicalSort(items.size(), items, indegree, graph);
    for(int i = 0; i < result.size(); i++) { // 결과 출력
        cout << result[i] << '\n';
    }
    return 0;
}