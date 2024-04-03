#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> si;

const string ICN = "ICN";

bool find_route = false;

vector<bool> used;
vector<string> answer;

bool cmp(si &a, si &b) {
    return a.first < b.first;
}

void backtracking(string curr, int cnt, int n, vector<vector<string>> tickets) {
    if(find_route || cnt == n + 1) {
        find_route = true;
        return;
    }

    vector<si> nexts;
    for(int i = 0; i < n; i++) {
        if(used[i] || curr != tickets[i][0]) {
            continue;
        }
        nexts.push_back({tickets[i][1], i});
    }

    sort(nexts.begin(), nexts.end(), cmp);

    for(int i = 0; i < nexts.size(); i++) {
        if(find_route) {
            return;
        }

        string next = nexts[i].first;
        int ticket = nexts[i].second;

        used[ticket] = true;
        answer[cnt] = next;
        backtracking(next, cnt + 1, n, tickets);
        used[ticket] = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int n = tickets.size();

    used.assign(n, false);
    answer.assign(n + 1, "");

    answer[0] = ICN;
    backtracking(ICN, 1, n, tickets);

    return answer;
}