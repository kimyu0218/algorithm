#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer (prices.size(), 0);

    // (i : 과거, j : 현재)
    for(int i = 0; i < prices.size(); i++) {
        for(int j = i+1; j < prices.size(); j++) {
            answer[i] = j - i;
            if(prices[i] > prices[j]) break; // 주식 가격 증가하지 않는 경우
        }
    }
    return answer;
}