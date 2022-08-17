#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int p1 = 0, p2 = people.size()-1; // p1 : 가벼운 사람, p2 : 무거운 사람
    while(p1 < p2) {
        // 1. 제한 무게를 초과하는 경우 : 무거운 사람 따로 태우기
        if(people[p1] + people[p2] > limit) { answer++; p2--; }
        // 2. 제한 무게를 초과하지 않는 경우 : 두 사람 태우기
        else { answer++; p1++; p2--; }
    }
    if(p1 == p2) answer++; // 한 사람이 남는 경우
    return answer;
}