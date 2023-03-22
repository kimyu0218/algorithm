#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isNum(char c) {
    return (c >= '0' && c <= '9');
}

string toLowercase(string s) {
    string result = "";
    for(int i = 0; i < s.length(); i++) {
        result += tolower(s[i]);
    }
    return result;
}

vector<string> splitFileName(string file) {
    vector<string> result;
    int i = 0, len = file.length(), max_len = 5;

    string tmp = "";
    while(i < len) { // HEAD 분리하기 (only 문자)
        if(isNum(file[i])) { // HEAD 끝나는 지점 발견
            break;
        }
        tmp += file[i++];
    }
    result.push_back(tmp); // HEAD 부분 push

    tmp = "";
    while(i < len && max_len--) { // NUMBER 분리하기 (only 숫자, 최대 다섯 글자)
        if(!isNum(file[i])) { // NUMBER 끝나는 지점 발견
            break;
        }
        tmp += file[i++];
    }
    result.push_back(tmp); // NUMBER 부분 push

    tmp = "";
    while(i < len) { // TAIL 분리하기
        tmp += file[i++];
    }
    result.push_back(tmp); // TAIL 부분 push

    return result;
}

bool cmp(const vector<string> &f1, const vector<string> &f2) {
    string h1 = toLowercase(f1[0]), h2 = toLowercase(f2[0]);
    if(h1 != h2) { // HEAD 기준 정렬
        return h1 < h2;
    }
    if(f1[1] != f2[1]) { // NUMBER 기준 정렬
        return stoi(f1[1]) < stoi(f2[1]);
    }
    return false; // 순서 유지
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> file_segment;
    int n = files.size();렬

    // 파일 분해
    for(int i = 0; i < n; i++) {
        file_segment.push_back(splitFileName(files[i]));
    }

    // 파일 정렬
    stable_sort(file_segment.begin(), file_segment.end(), cmp);

    // 파일 합치기
    for(int i = 0; i < n; i++) {
        string name = "";
        for(int j = 0; j < file_segment[i].size(); j++) {
            name += file_segment[i][j];
        }
        answer.push_back(name);
    }
    return answer;
}