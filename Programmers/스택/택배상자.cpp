#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0, n = order.size();
    stack<int> main_belt, sub_belt; // 컨테이너 벨트

    for(int i = n; i >= 1; i--) { // 컨테이너 벨트에 오름차순으로 상자 push
        main_belt.push(i);
    }

    for(int i = 0; i < n; i++) {
        int box = order[i];

        // 1. 보조 컨테이너 벨트 확인 (-> 보조 컨테이너는 마지막 요소만 확인)
        if(!sub_belt.empty() && box == sub_belt.top()) { // 보조 컨테이너 벨트에서 상자 찾음
            sub_belt.pop();
            answer++;
            continue;
        }

        // 2. 컨테이너 벨트 확인
        while(!main_belt.empty() && box != main_belt.top()) { // 컨테이너 벨트 -> 보조 컨테이너 벨트
            sub_belt.push(main_belt.top());
            main_belt.pop();
        }
        if(main_belt.empty()) { // 종료 조건 : 이동이 끝났지만 상자 찾을 수 없음
            break;
        }
        if(box == main_belt.top()) { // 컨테이너 벨트에서 상자 찾음
            main_belt.pop();
            answer++;
        }
    }
    return answer;
}