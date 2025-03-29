#include <iostream>
#include <vector>

using namespace std;

const int CNT = 20;

double convert_to_grade(string str_grade) {
    if(str_grade == "F") {
        return 0;
    }
    char alpha = str_grade[0];
    bool is_plus = (str_grade[1] == '+');
    return 4 - (alpha - 'A') + (is_plus ? 0.5 : 0);
}

double solution(vector<vector<string>> lectures) {
    int g_cnt = 0;
    double g_sum = 0;

    for(int i = 0; i < lectures.size(); i++) {
        string g = lectures[i][2];
        if(g == "P") {
            continue;
        }
        int cnt = (int) stod(lectures[i][1]);
        double grade = convert_to_grade(lectures[i][2]);

        g_cnt += cnt;
        g_sum += (grade * cnt);
    }
    return g_sum / g_cnt;
}

int main() {
    vector<vector<string>> lectures (CNT, vector<string> (3, ""));

    for(int i = 0; i < CNT; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> lectures[i][j];
        }
    }

    cout << solution(lectures);
    return 0;
}