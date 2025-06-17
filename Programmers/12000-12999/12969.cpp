#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const char SPACE = ' ';

vector<int> split_numbers(string s) {
    vector<int> numbers;
    int n = s.length();
    string tmp = "";

    for(int i = 0; i < n; i++) {
        if(s[i] == SPACE) {
            numbers.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp += s[i];
    }
    numbers.push_back(stoi(tmp));
    return numbers;
}

string solution(string s) {
    vector<int> numbers = split_numbers(s);

    int n = numbers.size();
    sort(numbers.begin(), numbers.end());
    return to_string(numbers[0]) + " " + to_string(numbers[n - 1]);
}