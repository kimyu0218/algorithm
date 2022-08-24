#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

set<string> get_gem_type(vector<string> gems) {
    set<string> gem_type; // 보석 종류 저장하는 셋
    for(int i = 0; i < gems.size(); i++) // 보석 종류 세팅
        gem_type.insert(gems[i]);
    return gem_type;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);

    set<string> gem_type = get_gem_type(gems); // 보석 종류
    map<string, int> m; // 해당 구간에 들어있는 보석별 개수

    int size = gems.size(), min_range = size, cnt_unique = gem_type.size();
    int left = 0, right = 0; // 투 포인터
    m[gems[left]]++; // 초기 상태 (0번째 보석만 포함)

    while(left <= right && right < size) {
        if(m.size() == cnt_unique) { // 1. 모든 보석 포함
            int range = right - left; // 구간의 길이 계산
            if(range < min_range) { // 가장 짧은 구간 발견 -> 답 갱신
                min_range = range;
                answer = { left + 1, right + 1 };
            }
            // 모든 보석을 포함하므로 구간 줄이기
            m[gems[left]]--;
            if(m[gems[left]] == 0) m.erase(gems[left]); // 해당 보석이 없어진 경우 맵에서 지우기
            left++;
        }
        else { // 2. 모든 보석을 포함하지 않음 -> 구간 늘리기
            if(++right == size) break;
            m[gems[right]]++;
        }
    }
    return answer;
}