class Solution {
public:
    bool isPalindrome(string s) {
        int last = s.length()-1;
        for(int i = 0; i <= last/2; i++) {
            if(s[i] != s[last-i]) {
                return false;
            }
        }
        return true;
    }

    void backtracking(int idx, int n, string sub, string s, vector<string> subset, vector<vector<string>> &answer) {
        if(idx == n) {
            if(isPalindrome(sub)) {
                subset.push_back(sub);
                answer.push_back(subset);
            }
            return;
        }

        if(sub == "") {
            sub += s[idx];
            backtracking(idx+1, n, sub, s, subset, answer);
        }
        else {
            if(isPalindrome(sub)) {
                vector<string> tmp = subset;
                tmp.push_back(sub);
                backtracking(idx, n, "", s, tmp, answer);
            }
            sub += s[idx];
            backtracking(idx+1, n, sub, s, subset, answer);
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        int n = s.length();
        backtracking(0, n, "", s, {}, answer);
        return answer;
    }
};