class Solution {
public:
    void backtracking(int open, int close, int n, string parentheses, vector<string> &answer) {
        if(open == n) {
            while(close < n) {
                parentheses += ')';
                close++;
            }
            answer.push_back(parentheses);
            return;
        }

        backtracking(open+1, close, n, parentheses+'(', answer); // add open bracket
        if(open > close) {
            backtracking(open, close+1, n, parentheses+')', answer); // add close bracket
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        backtracking(0, 0, n, "", answer);
        return answer;
    }
};