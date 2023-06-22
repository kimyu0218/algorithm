#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> splitSet(string s) { // 닫는 중괄호 기준으로 집합 자르기
    vector<string> v;
    string tmp = "";
    for(int i = 2; i < s.length(); i++) { // (2 : 가장 앞의 여는 중괄호 2개 제외)
        if(s[i] == '}') {
            v.push_back(tmp);
            tmp = "";
            i += 2; // (2 : 콤마와 여는 중괄호 pass)
        }
        else {
            tmp += s[i];
        }
    }
    return v;
}

vector<vector<int>> splitElement(string s) { // 집합과 원소 자르기
    vector<vector<int>> result;
    vector<string> v = splitSet(s); // 집합 자르기
    for(int i = 0; i < v.size(); i++) { // 집합별 원소 자르기
        string buff = "";
        vector<int> res;
        for(int j = 0; j < v[i].length(); j++) {
            if(v[i][j] == ',') {
                res.push_back(stoi(buff));
                buff = "";
            }
            else {
                buff += v[i][j];
            }
        }
        res.push_back(stoi(buff));
        result.push_back(res);
    }
    return result;
}

bool cmp(const vector<int> &v1, const vector<int> &v2) { // 원소 개수 오름차순 정렬
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<vector<int>> set = splitElement(s);
    sort(set.begin(), set.end(), cmp); // 집합 정렬

    vector<int> answer = {set[0]};
    map<int, int> pre; // 이전 원소 개수
    pre[set[0][0]]++;

    for(int i = 1; i < set.size(); i++) {
        map<int, int> next; // 현재 원소 개수
        for(int j = 0; j < set[i].size(); j++) {
            int num = set[i][j];
            next[num]++;
            if(next[num] > pre[num]) { // num의 개수 달라진 경, 튜플에 원소 추가
                answer.push_back(num);
            }
        }
        pre = next;
    }
    return answer;
}