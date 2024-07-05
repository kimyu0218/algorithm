#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0, n = topping.size();
    map<int, int> m1, m2;
    for(int i = 0; i < n; i++) {
        m2[topping[i]]++;
    }

    for(int i = 0; i < n; i++) { // i : 자르는 지점
        m1[topping[i]]++;
        m2[topping[i]]--;
        if(m2[topping[i]] == 0) {
            m2.erase(topping[i]);
        }

        if(m1.size()-m2.size() == 0) { // 공평하게 자르기 성공
            answer++;
        }
    }
    return answer;
}