#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int SIZE = 26;

vector<int> lzw(string s) { // lzw 압축
    vector<int> answer;
    int idx = 0, len = s.length();
    map<string, int> dic; // 사전

    for(int i = 0; i < SIZE; i++) { // 사전 초기화
        string ch = "";
        ch += (char)('A'+i);
        dic[ch] = i+1;
    }

    while(idx < len) {
        int c;
        string w = ""; // 가장 긴 문자열 w
        for(c= idx; c < len; c++) {
            if(dic[w+s[c]]) {
               w += s[c];
            }
            else { // w+s[c]는 사전에 존재하지 않음
                break;
            }
        }

        answer.push_back(dic[w]); // w의 색인번호 출력
        dic[w+s[c]] = dic.size(); // w+c 사전에 등록
        idx = c;
    }
    return answer;
}

vector<int> solution(string msg) {
    return lzw(msg);
}