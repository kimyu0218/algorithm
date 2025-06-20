#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> make_score_map(int n, vector<string> name, vector<int> yearning) {
    map<string, int> scores;

    for(int i = 0; i < n; i++) {
        scores[name[i]] = yearning[i];
    }
    return scores;
}

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    int n = photo.size();
    vector<int> answer (n, 0);
    map<string, int> scores = make_score_map(name.size(), name, yearning);

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < photo[i].size(); j++) {
            sum += scores[photo[i][j]];
        }
        answer[i] = sum;
    }
    return answer;
}