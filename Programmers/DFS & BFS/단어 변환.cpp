#include <string>
#include <vector>
#include <queue>

using namespace std;

struct info {
    string s;
    int step;
};

int cnt_diff(string s1, string s2) {
    int result = 0;
    for(int i = 0; i < s1.length(); i++) {
        result += (s1[i] != s2[i]);
    }
    return result;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    int n = words.size();
    vector<bool> visited(n, false);

    queue<info> q;
    q.push({begin, 0});

    while(!q.empty()) {
        string curr = q.front().s;
        int step = q.front().step;
        q.pop();

        if(curr == target) {
            return step;
        }

        for(int i = 0; i < n; i++) {
            if(visited[i] || cnt_diff(curr, words[i]) != 1) {
                continue;
            }
            visited[i] = true;
            q.push({words[i], step + 1});
        }
    }
    return 0;
}