#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pi;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> answer(n, -1);
    stack<pi> s; // (first: 숫자, second: 인덱스)

    for(int i = 0; i < n; i++) {
        /*
         * 스택 : 뒷 큰수를 아직 알 수 없는 경우, 스택에 임시 저장
         * 뒷 큰수를 알 수 없다?
         * 1) 가장 최근에 들어간 수
         * 2) 자신보다 큰 수가 발견되지 않음
        */

        // 스택에 들어있는 수 검사 : 뒷 큰수를 발견할 수 있는가
        // numbers[i] : 가장 최근에 나온 숫자 == 스택에 들어있는 숫자보다 뒤의 순서
        while(!s.empty() && numbers[i] > s.top().first) {
            answer[s.top().second] = numbers[i];
            s.pop();
        }
        s.push({numbers[i], i}); // 가장 최근의 숫자 push
    }
    return answer;
}