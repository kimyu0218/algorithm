#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx;

bool cmp(string &s1, string &s2) {
    if(s1[idx] != s2[idx]) {
        return s1[idx] < s2[idx];
    }
    return s1 < s2;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;

    idx = n;
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}