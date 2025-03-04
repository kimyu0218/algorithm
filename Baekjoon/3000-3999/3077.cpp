#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, int> make_map(int n, vector<string> answer) {
    map<string, int> m;
    for(int i = 0; i < n; i++) {
        m[answer[i]] = i + 1;
    }
    return m;
}

string solution(vector<string> answer, vector<string> hyunwoo) {
    int score = 0;
    int n = answer.size();

    map<string, int> m = make_map(n, answer);

    for(int i = 0; i < n; i++) {
        string s1 = hyunwoo[i];
        for(int j = i; j < n; j++) {
            string s2 = hyunwoo[j];
            if(m[s1] < m[s2]) {
                score++;
            }
        }
    }
    return to_string(score) + '/' + to_string(n * (n - 1) / 2);
}

int main() {
    int n;
    vector<string> answer, hyunwoo;

    cin >> n;

    answer.assign(n, "");
    for(int i = 0; i < n; i++) {
        cin >> answer[i];
    }
    hyunwoo.assign(n, "");
    for(int i = 0; i < n; i++) {
        cin >> hyunwoo[i];
    }

    cout << solution(answer, hyunwoo);
    return 0;
}