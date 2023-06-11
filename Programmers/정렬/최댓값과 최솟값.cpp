#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> split(string s) { // 공백 기준 split한 수열 반환
    vector<int> result;
    string tmp = "";
    for(int i = 0; i <= s.length(); i++) {
        if(s[i] == ' ') {
            result.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp += s[i];
    }
    result.push_back(stoi(tmp));
    return result;
}

string solution(string s) {
    vector<int> arr = split(s);
    sort(arr.begin(), arr.end()); // 오름차순 정렬
    return to_string(arr[0]) + " " + to_string(arr[arr.size()-1]);
}