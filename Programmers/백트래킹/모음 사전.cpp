#include <string>
#include <vector>
#include <set>

using namespace std;

char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
set<string> words;

void backtracking(string word) {
    if(word.length() == 5) {
        return;
    }

    for(int i = 0; i < 5; i++) {
        string new_word = word + vowels[i];
        words.insert(new_word);
        backtracking(new_word);
    }
}

int solution(string word) {
    int answer = 1;

    backtracking("");

    for(auto iter = words.begin(); iter != words.end(); iter++) {
        if(word == *iter) {
            return answer;
        }
        answer++;
    }
}