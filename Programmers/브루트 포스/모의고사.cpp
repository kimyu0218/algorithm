#include <string>
#include <vector>

using namespace std;

vector<vector<int>> patterns = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
};

vector<int> make_answer(int n, int p) {
    vector<int> result(n, 0);

    int idx = 0;
    int p_len = patterns[p].size();

    for(int i = 0; i < n; i++) {
        result[i] = patterns[p][idx];
        idx = (idx + 1) % p_len;
    }
    return result;
}


vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int n = answers.size();

    vector<vector<int>> answer_sheets(3, vector<int> (0));
    for(int i = 0; i < 3; i++) {
        answer_sheets[i] = make_answer(n, i);
    }

    vector<int> sums(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            if(answers[i] == answer_sheets[j][i]) {
                sums[j]++;
            }
        }
    }

    int max_score = max(sums[0], max(sums[1], sums[2]));
    for(int i = 0; i < 3; i++) {
        if(max_score == sums[i]) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}