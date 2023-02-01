#include <string>
#include <vector>

using namespace std;

int result = 0;

void dfs(int idx, vector<int> numbers, int pre, int target) {
    if(idx == numbers.size()) { // 기저 조건
        if(pre == target) result++; // 타겟 만들기 성공
        return;
    }
    dfs(idx+1, numbers, pre + numbers[idx], target); // 1. 더하기
    dfs(idx+1, numbers, pre - numbers[idx], target); // 2. 빼기
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(0, numbers, 0, target);
    return answer = result;
}