#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;

    int n = numbers.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }
            s.insert(numbers[i] + numbers[j]);
        }
    }

    for(auto iter = s.begin(); iter != s.end(); iter++) {
        answer.push_back(*iter);
    }
    return answer;
}