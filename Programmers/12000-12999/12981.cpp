#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool is_valid_answer(char ch, int len, string word) {
    if(len == 1) {
        return false;
    }
    return (word[0] == ch);
}

vector<int> solution(int n, vector<string> words) {
    int m = words.size();
    set<string> s;

    char ch = words[0][0];
    for(int i = 0; i < m; i++) {
        string word = words[i];
        int len = word.length();

        int person = i % n + 1;
        int order = i / n + 1;

        if(!is_valid_answer(ch, len, word) || s.find(word) != s.end()) {
            return { person, order };
        }
        s.insert(word);
        ch = word[len - 1];
    }
    return { 0, 0 };
}