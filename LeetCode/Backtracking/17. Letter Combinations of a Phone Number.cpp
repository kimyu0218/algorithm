class Solution {
public:
    map<int, char> digit;

    void backtracking(int idx, int n, string digits, string letter, vector<string> &answer) {
        if(idx == n) {
            answer.push_back(letter);
            return;
        }

        int num = digits[idx]-'0', types = 3;
        if(num == 7 || num == 9) {
            types++;
        }
        for(int i = 0; i < types; i++) {
            char ch = digit[num] + i;
            backtracking(idx+1, n, digits, letter + ch, answer);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if(digits == "") {
            return answer;
        }
        digit[2] = 'a';
        digit[3] = 'd';
        digit[4] = 'g';
        digit[5] = 'j';
        digit[6] = 'm';
        digit[7] = 'p';
        digit[8] = 't';
        digit[9] = 'w';

        int n = digits.length();
        backtracking(0, n, digits, "", answer);
        return answer;
    }
};