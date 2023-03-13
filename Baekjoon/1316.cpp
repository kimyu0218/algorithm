#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 26;

bool isGroupWord(string &word) {
    vector<bool> visited(SIZE, false); // 방문 여부

    visited[word[0]-'a'] = true; // 첫번째 문자 세팅
    for(int i = 1; i < word.length(); i++) {
        if(!visited[word[i]-'a']) { // 새로운 문자가 등장한 경우
            visited[word[i]-'a'] = true;
        }
        else if(word[i] != word[i-1]) { // 그룹단어가 아닌 경우
            return false;
        }
    }
    return true;
}

int cntGroupWords(int n, vector<string> &words) { // 그룹단어 개수 세기
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += isGroupWord(words[i]);
    }
    return cnt;
}

int main() {
    int n; // 단어의 개수
    vector<string> words; // 단어

    // 입력
    cin >> n;
    words.assign(n, "");
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    // 연산 & 출력
    cout << cntGroupWords(n, words);
    return 0;
}