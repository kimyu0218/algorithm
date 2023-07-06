#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> &v1, const vector<int> &v2) {
    if(v1[1] != v2[1]) { // 1. 진출지점 빠른 순
        return v1[1] < v2[1];
    }
    return v1[0] < v2[0]; // 2. 진입지점 빠른 순
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), cmp);

    int answer = 1, pos = routes[0][1];
    int n = routes.size();
    for(int i = 1; i < n; i++) {
        if(routes[i][0] > pos) { // pos 위치의 단속 카메라로 i번째 지점 커버 불가
            answer++; // 카메라 하나 더 설치
            pos = routes[i][1]; // 카메라 위치 지정
        }
    }
    return answer;
}