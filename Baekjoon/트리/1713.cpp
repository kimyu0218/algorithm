#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

bool cmp(const pair<int, ci> &p1, const pair<int, ci> &p2) {
    // (first : 추천수, second : 순서)
    if(p1.second.first != p2.second.first) return p1.second.first < p2.second.first;
    return p1.second.second < p2.second.second;
}

map<int, ci> recommend(int n, int m, vector<int> &student) {
    map<int, ci> candidate; // 학생별 추천수, 순서

    for(int i = 0; i < m; i++) {
        // 1. 비어있는 사진틀이 없는 경우
        if(candidate.size() == n && candidate.find(student[i]) == candidate.end()) {
            candidate.erase(min_element(candidate.begin(), candidate.end(), cmp));
        }
        int node = student[i];
        if(candidate.find(node) == candidate.end()) candidate[node].second = i; // 최초 추천
        candidate[node].first++;
    }
    return candidate;
}

int main() {
    int n, m; // 사진틀 수, 총 학생 수
    cin >> n >> m;

    vector<int> student(m, 0);
    for(int i = 0; i < m; i++)
        cin >> student[i];

    map<int, ci> candidate = recommend(n, m, student);
    for(auto iter = candidate.begin(); iter != candidate.end(); iter++)
        cout << iter->first << ' ';
    return 0;
}