#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    int round = 0;
    map<string, int> m;

    for(int i = 0; i < words.size(); i++) {
        if(i % n == 0) { // 라운드 계산
            round++;
        }
        // 1. 앞사람이 말한 단어의 마지막 문자로 말하지 못한 경우
        if(i && words[i][0] != words[i-1][words[i-1].length()-1]) {
            return {i % n + 1, round};
        }
        // 2. 두 글자 이상의 단어를 말하지 않았거나, 이전에 등장한 단어를 사용한 경우
        if(words[i].length() < 2 || m[words[i]]++) {
            return {i % n + 1, round};
        }
    }
    return {0, 0};
}