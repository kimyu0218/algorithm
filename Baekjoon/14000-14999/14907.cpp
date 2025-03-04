#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int SIZE = 26;

vector<string> split(string input) { // 공백 기준으로 자르기
    vector<string> result;

    int pos = 0, len = input.length();
    for(int i = 0; i < len; i++) {
        if(input[i] == ' ') {
            result.push_back(input.substr(pos, i-pos));
            pos = i+1;
        }
    }
    result.push_back(input.substr(pos, len-pos));
    return result;
}

int topologicalSort(vector<int> indegree, vector<int> date, vector<vector<int>> graph) {
    int ans = 0;

    vector<int> dp (SIZE, 0);
    queue<int> q;
    for(int i = 0; i < SIZE; i++) {
        dp[i] = date[i];
        if(date[i] && !indegree[i]) { // 진입 차수가 0인 경우
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front(); q.pop();
        ans = max(ans, dp[node]);

        for(int i = 0; i < graph[node].size(); i++) { // 후속 작업 탐색
            int next = graph[node][i];
            indegree[next]--;
            if(!indegree[next]) { // 진입 차수가 0인 경우
                q.push(next);
            }
            dp[next] = max(dp[node] + date[next], dp[next]);
        }
    }
    return ans;
}

int main() {
    vector<int> indegree(SIZE, 0), date(SIZE, 0);
    vector<vector<int>> graph(SIZE, vector<int> (0));

    string input;
    while(getline(cin, input)) {
        vector<string> splits = split(input);

        int w = splits[0][0]-'A';
        int d = stoi(splits[1]);
        date[w] = d;

        if(splits.size() == 2) { // 선행 작업 없는 경우
            continue;
        }

        for(int i = 0; i < splits[2].length(); i++) { // t작업 후 w작업 시작
            int t = splits[2][i]-'A';
            indegree[w]++;
            graph[t].push_back(w);
        }
    }

    cout << topologicalSort(indegree, date, graph);
    return 0;
}