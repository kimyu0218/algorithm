#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 26;

bool is_group_word(string word) {
    vector<bool> find (SIZE, false);
    find[word[0] - 'a'] = true;

    for(int i = 1; i < word.length(); i++) {
        if(word[i] == word[i-1]) {
            continue;
        }
        int idx = word[i] - 'a';
        if(find[idx]) {
            return false;
        }
        find[idx] = true;
    }
    return true;
}

int solution(vector<string> words) {
    int result = 0;
    for(int i = 0; i < words.size(); i++) {
        result += is_group_word(words[i]);
    }
    return result;
}

int main() {
    int n;
    vector<string> words;

    cin >> n;

    words.assign(n, "");
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cout << solution(words);
    return 0;
}