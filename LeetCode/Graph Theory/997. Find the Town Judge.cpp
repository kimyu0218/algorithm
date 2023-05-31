class Solution {
public:
    // judge : trusts nobody
    // except judge : trusts judge
    // [a, b] : a trusts b
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> believe(n+1, false); // believe[i] : i person believes someone
        vector<int> cnt(n+1, 0); // cnt[i] : the number of people who trust i person
        for(int i = 0; i < trust.size(); i++) {
            int a = trust[i][0];
            int b = trust[i][1];

            believe[a] = true;
            cnt[b]++;
        }

        int judge = 0; // 0 : judge does not exist
        for(int i = 1; i <= n; i++) {
            if(!believe[i] && cnt[i] == n-1) {
                if(judge == 0) {
                    judge = i;
                }
                else { // does not satisfy that there is only one town judge
                    return -1;
                }
            }
        }
        return judge ? judge : -1;
    }
};