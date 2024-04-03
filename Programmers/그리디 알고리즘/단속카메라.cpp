#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2) {
    return v1[0] < v2[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end(), cmp);

    int pre_out = routes[0][1];
    for(int i = 1; i < routes.size(); i++) {
        int in = routes[i][0];
        int out = routes[i][1];

        if(in <= pre_out) {
            pre_out = min(pre_out, out);
            continue;
        }
        answer++;
        pre_out = out;
    }
    return answer;
}