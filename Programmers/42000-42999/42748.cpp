#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    int n = commands.size();
    vector<int> answer (n, 0);

    for(int i = 0; i < n; i++) {
        int s = commands[i][0] - 1;
        int e = commands[i][1] - 1;
        int k = commands[i][2] - 1;

        vector<int> sorted = array;
        sort(sorted.begin() + s, sorted.begin() + e + 1);

        answer[i] = sorted[s + k];
    }
    return answer;
}