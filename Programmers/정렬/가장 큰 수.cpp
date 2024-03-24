#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int &i1, int &i2) {
    string s1 = to_string(i1);
    string s2 = to_string(i2);
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);

    if(numbers[0] == 0) {
        return "0";
    }
    for(int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    return answer;
}